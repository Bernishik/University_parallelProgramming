#include <stdio.h>
#include <omp.h>
#include "locale.h"
#include <stdio.h>
#include <windows.h>
#include "math.h"
#include <time.h>
#include "stdlib.h"
#include <unistd.h>

#define  N 20000
int mass[N][N];


void generateMass(int n, int m[n][n]) {   // наповнення чисел випадковими числами

    for (int z = 0; z < n; z++) {
        for (int i = 0; i < n; i++) {
            m[z][i] = rand() % 100 + 1;
        }
    }
}

void printMass(int n, int m[n][n]) {
    for (int z = 0; z < n; z++) {
        for (int i = 0; i < n; i++) {
            printf("%d  ", m[z][i]);
        }
        printf("\n");
    }
}


int main() {
    system("chcp 65001");
    srand(time(NULL));

    generateMass(N, mass);
    int sum = 0;
    double firstTime, secondTime;
    double start_time, end_time;
    start_time = omp_get_wtime();
#pragma omp parallel for default(none) shared(mass)   num_threads(1) reduction(+:sum)
    for (int i = 0; i < N; i++) {
        int maxnum = 0;
        for (int z = 0; z < N; z++) {
            if (mass[i][z] > maxnum) {
                maxnum = mass[i][z];
            }

        }
        sum += maxnum;
        maxnum = 0;
    }
    end_time = omp_get_wtime();
    firstTime = end_time - start_time;
    printf("Сума максимальних чисел у рядках масиву -  %d\n", sum);
    printf("Час за який знайдено результат (1 потік) -  %f\n", firstTime);

    start_time = omp_get_wtime();
    sum = 0;
#pragma omp parallel for default(none) shared(mass)  num_threads(12) reduction(+:sum)
    for (int i = 0; i < N; i++) {
        int maxnum = 0;
        for (int z = 0; z < N; z++) {
            if (mass[i][z] > maxnum) {
                maxnum = mass[i][z];
            }

        }
        sum += maxnum;
        maxnum = 0;
    }


    end_time = omp_get_wtime();
    secondTime = end_time - start_time;

    printf("Сума максимальних чисел у рядках масиву -  %d\n", sum);
    printf("Час за який знайдено результат (12 потоків) -  %f\n", secondTime);
    printf("Программа виконала завдання з 12 потоками у %f раз швидше ніж в однопоточному режимі\n",
           firstTime / secondTime);


    return 0;
}
