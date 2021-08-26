#include <stdio.h>
#include <omp.h>
#include "locale.h"
#include <stdio.h>
#include <windows.h>


int main() {
    system("chcp 65001");
    int n, m;
    m = omp_get_max_threads();
#pragma omp parallel default(none) private(n) shared(m)  num_threads(6)
    {

        n = omp_get_thread_num();
        printf("i am %d thread from %d threads!\n", n, omp_get_num_threads());
#pragma omp single
        {
            printf("max threads num - %d\n", m);
        };

#pragma omp sections
        {
#pragma omp section
            {
                printf("перша секція процесс - %d\n",n);
            }
#pragma omp section
            {
                printf("друга секція процесс - %d\n",n);
            }
        };
    }


    return 0;
}
