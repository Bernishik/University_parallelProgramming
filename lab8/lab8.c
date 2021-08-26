#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <mpi.h>

double function(double x){
    return log2(pow(x, 3));
}

bool check_Runge(double first , double second, double epsilon){
    return (fabs(second - first) / 3) < epsilon;
}

int main(int argc, char* argv[]){
    int size, rank;
    int N = 10000;
    double start = 5.0, end = 1500.0;
    double t1, t2;
    int i,j;
    MPI_Init (&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    t1= MPI_Wtime();
    int count = (int) (N / (size - 1));
    double h = (end - start) / (double) N;

    if (rank == size - 1){
        printf("Основний процес [%d]:\n", rank);

        MPI_Request recv_requests[size - 1];
        MPI_Status status[size - 1];

        double results[size - 1][count];

        printf("Основний процес [%d]: Отримання результатів:\n", rank);
        for (j = 0; j < size - 1; j++){
            printf("Основний процес [%d]: Отримання з (%d)\n", rank, j);
            if (j == 0)
                count += N % count;
            MPI_Irecv(
                &results[j],
                count,
                MPI_DOUBLE,
                j,
                100,
                MPI_COMM_WORLD,
                &recv_requests[j]
            );
        }

        MPI_Waitall(size - 1, recv_requests, status);

        printf("Основний [%d]: Всі дані отримано від %d процесів\n", rank, size - 1);
        double result = 0;
        
        for (i = 0; i < size - 1; i++){
            for (j = 0; j < count; j++){
                result += results[i][j];
            }
        }

        result *= h;
        t2 = MPI_Wtime();
        printf("Основний процесс [%d]: Результат = %f\n", rank, result);
        printf("Основний процесс [%d]: Результат знайдено за %f секунд\n", rank, t2-t1);

    } else {
        for (i = 0; i < size - 1; i++){
            if (i == rank){
                printf("Процес [%d]:\n", rank);
                if (rank == 0)
                    count += N % count;
                double result[count];
                MPI_Request send_req;

                double x;
                if (rank == 0)
                    x = start;
                if (rank == 1)
                    x = start + (count + N % count) * h;
                if (rank > 1)
                    x = start + (count + N % count) * h + count * h * (i - 1);

                double start_x = x;
                
                result[0] = 0;
                for (j = 1; j < count; j++){
                    result[j] = function(x + 0.5 * h);
                    x += h;
                }

                printf("Процес [%d]: Count: %d Крок: %f\n", rank, count, h);

                printf("Процес [%d]: Відправляє дані основному процесу (%d)\n", rank, size - 1);
                MPI_Isend(&result, count, MPI_DOUBLE, size - 1, 100, MPI_COMM_WORLD, &send_req);
                MPI_Wait(&send_req, MPI_STATUS_IGNORE);
            }
        }
    }

    MPI_Finalize();
    return 0;
}
