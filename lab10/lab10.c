#include "mpi.h"
#include <stdio.h>


int main(int argc, char *argv[]){
    static int ranks[] = {0,1};
    int world_rank, world_size,prime_rank, prime_size;
    MPI_Comm new_com, new_comm;
    MPI_Group old_group, new_group;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_group(MPI_COMM_WORLD, &old_group);
    MPI_Group_incl(old_group, 2, ranks, &new_group);
    MPI_Comm_create(MPI_COMM_WORLD,new_group, &new_comm);

    if (MPI_COMM_NULL != new_comm){
        MPI_Comm_size(new_comm, &prime_size);
        MPI_Comm_rank(new_comm, &prime_rank);
        int d[2];
        if (prime_rank == 0)
        {
            d[0] = 200;
            d[1] = 201;
        }
        MPI_Bcast(&d,2,MPI_INT,0,new_comm);

        printf("MPI_COMM_WORLD: %d from %d. New_comm: %d from %d message = %d \n ", world_rank,world_size, prime_rank,prime_size,d[prime_rank]);
        MPI_Group_free(&new_group);
        MPI_Comm_free(&new_comm);
    }
    MPI_Group_free(&old_group);
    MPI_Finalize();
    return 0;
}
