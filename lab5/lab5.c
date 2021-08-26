#include <mpi.h>
#include <stdio.h>
int main (int argc , char ** argv )
{
    int size , rank ;
    int llwn;
    char nam[100];
    MPI_Init(&argc , &argv ) ;

    MPI_Comm_size(MPI_COMM_WORLD, &size) ;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank ) ;
    MPI_Get_processor_name((char *) &nam, &llwn);

    printf ( "I am %d process from %d(%s)\n" , rank ,size,nam) ;
    MPI_Finalize();
    return 0;
}
