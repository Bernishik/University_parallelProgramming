#pragma comment (lib, "cublas.lib")
#pragma comment (lib, "curand.lib")

#include <cstdlib>
#include <curand.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <cublas_v2.h>

void GPU_fill_rand(float *A, int nr_rows_A, int nr_cols_A) {
    curandGenerator_t prng;
    curandCreateGenerator(&prng, CURAND_RNG_PSEUDO_DEFAULT);
    curandSetPseudoRandomGeneratorSeed(prng, time(0));
    curandGenerateUniform(prng, A, nr_rows_A * nr_cols_A);
}

void gpu_blas_mmul(const float *A, const float *B, float *C, const int m, const int k, const int n) {
    int lda = m, ldb = k, ldc = m;
    const float alf = 1;
    const float bet = 0;
    const float *alpha = &alf;
    const float *beta = &bet;
    cublasHandle_t handle;
    cublasCreate(&handle);
    cublasSgemm(handle, CUBLAS_OP_N, CUBLAS_OP_N, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
    cublasDestroy(handle);
}

void print_matrix(const float *A, int nr_rows_A, int nr_cols_A) {
    for (int i = 0; i < nr_rows_A; ++i) {
        for (int j = 0; j < nr_cols_A; ++j) {
            printf("%f  ", A[j * nr_rows_A + i]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int m, k, n;
    m = 10000;
    k = 10000;
    n = 10000;
    float *h_A = (float *) malloc(m * k * sizeof(float));
    float *h_B = (float *) malloc(n * k * sizeof(float));
    float *h_C = (float *) malloc(m * n * sizeof(float));

    float *d_A, *d_B, *d_C;
    cudaMalloc(&d_A, m * k * sizeof(float));
    cudaMalloc(&d_B, n * k * sizeof(float));
    cudaMalloc(&d_C, m * n * sizeof(float));

    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    cudaEventRecord(start, 0);
    GPU_fill_rand(d_A, m, k);
    GPU_fill_rand(d_B, n, k);

    cudaMemcpy(h_A, d_A, m * k * sizeof(float), cudaMemcpyDeviceToHost);
    cudaMemcpy(h_B, d_B, n * k * sizeof(float), cudaMemcpyDeviceToHost);
//    printf("A:\n");
//    print_matrix(h_A, m, k);
//    printf("B:\n");
//    print_matrix(h_B, n, k);

    gpu_blas_mmul(d_A, d_B, d_C, m, k, k);

    cudaMemcpy(h_C, d_C, m * n * sizeof(float), cudaMemcpyDeviceToHost);
//    printf("C:\n");
//    print_matrix(h_C, m, n);
    cudaEventRecord(stop,0);
    cudaEventSynchronize(stop);
    float milliseconds = 0;
    cudaEventElapsedTime(&milliseconds, start, stop);
    printf("The time is %.6f ms\n", milliseconds);
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    free(h_A);
    free(h_B);
    free(h_C);
    return 0;
}

// nvcc -o lab12_3 lab_12_3.cu -lcurand -lcublas

