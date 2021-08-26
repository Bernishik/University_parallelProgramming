#include <stdio.h>
#include "omp.h"

#include "stdlib.h"

#define  N 1000
double A[N][N];
double L[N][N];
double U[N][N];
double R[N][N];


void generateMass(int a, int b, int n, double A_[n][n], double L_[n][n],
                  double U_[n][n]) {   // наповнення чисел випадковими числами

    for (int z = 0; z < n; z++) {
        for (int i = 0; i < n; i++) {
            A_[z][i] = rand() % (b - a + 1) - a;
            L_[z][i] = 0;
            U_[z][i] = 0;
            if (z == i)
                U_[z][i] = 1;
        }
    }
}

void printMass(int n, double m[n][n]) {
    for (int z = 0; z < n; z++) {
        for (int i = 0; i < n; i++) {
            printf("%f  ", m[z][i]);
        }
        printf("\n");
    }
}

void printMass_int(int n, double m[n][n]) {
    for (int z = 0; z < n; z++) {
        for (int i = 0; i < n; i++) {
            printf("%d  ", (int) m[z][i]);
        }
        printf("\n");
    }
}

void proisv(int n, double L_[n][n], double U_[n][n], double R_[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                R_[i][j] += L_[i][k] * U_[k][j];
}

int Validate_LU(int n, double A_[n][n], double R_[n][n]){
    int i,j,res = 1;
    for(i= 0; i<n;i++){
        for(j=0;j<n;j++){
            if (A_[i][j] != R_[i][j]){
                res =0;
                break;
            }
        }
        if(res == 0)
            break;
    }
    return res;
}

int main() {
    system("chcp 65001");
    double sum = 0;
    double start_time = 0, end_time = 0, time;
    // генер
    generateMass(0, 50, N, A, L, U);
    printf("Згенерована матриця:\n");
//    printMass_int(N, A);
    printf("\n");
    int user_choise = 0;
    printf("Виберіть тип програми 1-послідовна, 2-паралельна, 3-таски\n");
    scanf("%d", &user_choise);


    int i, j, k;
    start_time = omp_get_wtime();
    if (user_choise == 1) {
        for (i = 0; i < N; i++) {
            L[i][0] = A[i][0];
            U[0][i] = A[0][i] / L[0][0];
        }

        for (i = 1; i < N; i++) {
            for (j = 1; j < N; j++) {
                if (i >= j)
                {
                    sum = 0;
                    for (k = 0; k < j; k++)
                        sum += L[i][k] * U[k][j];

                    L[i][j] = A[i][j] - sum;
                } else // верхнiй
                {
                    sum = 0;
                    for (k = 0; k < i; k++)
                        sum += L[i][k] * U[k][j];

                    U[i][j] = (A[i][j] - sum) / L[i][i];
                }
            }
        }

    } else if (user_choise == 2) {

        for (i = 0; i < N; i++) {
            L[i][0] = A[i][0];
            U[0][i] = A[0][i] / L[0][0];
        }

#pragma omp parallel for private (i, j, k, sum)  shared(A, L, U) default(none) num_threads(12) ordered
        for (i = 1; i < N; i++) {
#pragma omp ordered
            for (j = 1; j < N; j++) {
                if (i >= j)
                {
                    sum = 0;
                    for (k = 0; k < j; k++)
                        sum += L[i][k] * U[k][j];

                    L[i][j] = A[i][j] - sum;
                } else // верхнiй
                {
                    sum = 0;
                    for (k = 0; k < i; k++)
                        sum += L[i][k] * U[k][j];

                    U[i][j] = (A[i][j] - sum) / L[i][i];
                }
            }
        }

    } else if (user_choise == 3) {
        for (i = 0; i < N; i++) {
            L[i][0] = A[i][0];
            U[0][i] = A[0][i] / L[0][0];
        }

#pragma omp parallel  private (i, j, k, sum)  shared(A, L, U) default(none) num_threads(12)
        {

                for (i = 1; i < N; i++) {

#pragma omp task default(none) private(sum, k, i, j) shared(L, U, A)
                    {
                        for (j = 1; j < N; j++) {

                            if (i >= j)
                            {
                                sum = 0;
                                for (k = 0; k < j; k++)
#pragma omp atomic
                                    sum += L[i][k] * U[k][j];

                                L[i][j] = A[i][j] - sum;
                            } else // верхнiй
                            {
                                sum = 0;
                                for (k = 0; k < i; k++)
#pragma omp atomic
                                    sum += L[i][k] * U[k][j];

                                U[i][j] = (A[i][j] - sum) / L[i][i];
                            }
                        }
                    }

            }
        }
    }

    end_time = omp_get_wtime();
    time = end_time - start_time;
    printf("Час виконання  %f\n", time);


//    printf("L матриця:\n");
//    printMass(N,L);
//    printf("U матриця:\n");
//    printMass(N,U);
    printf("\n");

    proisv(N, L, U, R);
    printf("Перевірка Розкладу матриці:\n");
//    if(){
//        printf("Матриці рівні");
//    }else{
//        printf("Матриці не рівні");
//    }
//    printMass_int(N, R);
    printf("\n");
    return 0;
}
