#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
    int rank, rc;
    int mass[10];
    int mass2[10];
    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    srand(time(NULL));
    if (rank == 0)
    {
	int i=0;
        for (i=0;i<=9;i++)
        {
            mass[i]= rand() % 10;
        }
        MPI_Send(&mass, 10, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&mass2, 10, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);
        printf("\nПочаткові дані: \n");
        for (i=0;i<10;i++)
        {
            printf(" %d \t", mass[i]);
        }
        printf("\nОтримані дані: \n");
        for (i=0;i<=9;i++)
        {
             printf(" %d \t", mass2[i]);
        }
        printf("\n");
    }
    else
    if (rank == 1)
        {
	int i=0;
            MPI_Recv(&mass, 10, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
            for (i=0;i<=9;i++)
            {
                mass2[i]= mass[i] * 2;
            }
            MPI_Send(&mass2, 10, MPI_INT, 0, 1, MPI_COMM_WORLD);
        }
    MPI_Finalize();
      return 0;
}
