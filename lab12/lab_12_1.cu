#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
int main()
{
    const int m=100;
    const int k=100;
    const int n=100;
    int a[m][k];
    int b[k][n];
    int c[m][n];
    int i,j,q;
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    cudaEventRecord(start,0);
//    printf("matrix A\n");
     for( i = 0; i < m; i++)
        {
             for( j = 0; j < k; j++)
             {
                a[i][j]=rand()%10+1;
//                printf( " %d \t" , a[i][j] ) ;
             }
//              printf("\n");
        }
//    printf("matrix B\n");
        for( i = 0; i < k; i++)
        {
             for( j = 0; j < n; j++)
             {
                b[i][j]=rand()%10+1;
//                printf( " %d \t" , b[i][j] ) ;
             }
//             printf("\n");
        }
//    printf("Result of multiplying\n");
     for(i = 0; i < m; i++)
     {
        for(j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for(q = 0; q < k; q++)
                c[i][j] += a[i][q] * b[q][j];
//            printf( " %d \t" , c[i][j] ) ;
        }
//        printf("\n");
     }
     cudaEventRecord(stop,0);
     cudaEventSynchronize(stop);
    float milliseconds = 0;
    cudaEventElapsedTime(&milliseconds, start, stop);
    printf("The time is %.6f ms\n", milliseconds);
    return 0;
}

