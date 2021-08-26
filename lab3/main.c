#include <stdio.h>
#include "omp.h"

#include "stdlib.h"


omp_lock_t lock;
double f(double x){
    return (-3*x*x+2*x+9);
}


int main() {
    system("chcp 65001");
    int n; double a,b,y,h,result;
    double start_time = 0, end_time = 0,time;
    int user_choise =0;
    a = -1;
    b = 2;
    n = 1500; //кількість точок
    printf("Виберіть тип синхронізації 1-атомік, 2-замки, 3-крітікал\n");
    scanf("%d",&user_choise);
    h= (b - a) / n; //  крок
    y =0;
    if (user_choise==1){
        start_time = omp_get_wtime();
#pragma omp parallel for default(none) num_threads(12) shared(n,a,h,y)
            for (int i = 1; i < n; i++) {
                #pragma omp atomic
                y += 2 * (f(a + h * i));

            }
        end_time = omp_get_wtime();

    }
    else if(user_choise == 2) {

        start_time = omp_get_wtime();
        omp_init_lock(&lock);
#pragma omp parallel for default(none) num_threads(12) shared(n,a,h,y, lock)
        for (int i = 1; i < n; i++) {
            omp_set_lock(&lock);
            y += 2 * (f(a + h * i));
            omp_unset_lock(&lock);

        }
        omp_destroy_lock(&lock);
        end_time = omp_get_wtime();


    }else if(user_choise == 3) {
        start_time = omp_get_wtime();

#pragma omp parallel for default(none) num_threads(12) shared(n,a,h,y)
        for (int i = 1; i < n; i++) {
#pragma omp critical
            {
            y += 2 * (f(a + h * i));
        }

        }
        end_time = omp_get_wtime();
    }
    y += f(a)+f(b);
    time = end_time - start_time;
        printf("Час виконання  %f\n",time);
    result= (h / 2) * y;
    printf("%f",result);
}
