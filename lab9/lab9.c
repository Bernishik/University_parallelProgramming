#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

int *createMatrix (int nrows, int ncols) {
    int *matrix;
    int h, i, j;

    if ((matrix = malloc(nrows * ncols * sizeof(int))) == NULL) {
        printf("Malloc error");
        exit(1);
    }
    srand(time( NULL ));
    for (h = 0; h < nrows * ncols; h++) {
        matrix[h] = rand() % 50;
    }

    return matrix;
}

void printArray(int *row, int nElements) {
    int i;
    for (i=0; i < nElements; i++) {
        printf("%d ", row[i]);
    }
    printf("\n");
}


int main (int argc, char **argv) {
    int *matrix;
    MPI_Init(&argc, &argv);

    int p, id;
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    if (id == 0) {
        matrix = createMatrix(p, p);
        printArray(matrix,p*p);
    }

    int *Row = malloc(sizeof(int) * p);
    MPI_Scatter(matrix, p, MPI_INT, Row, p, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d get elements: ", id);
    printArray(Row, p);

    int max_row = 0;
    int i;
    for (i = 0; i < p; i++)
    {
        if(Row[i] > max_row){
            max_row = Row[i];
        }
    }

    int sum;
    MPI_Reduce(&max_row, &sum, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if (id == 0) {
        printf("Max value = %d\n", sum);
    }

    MPI_Finalize();
    return 0;
}
