#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <stddef.h>

void generateMass(int n, int m[n]) {   // наповнення чисел випадковими числами

    for (int z = 0; z < n; z++) {

            m[z]= rand() % 100 + 1;

    }
}



int main(int argc, char ** argv) {
    int NUMBER_OF_PROCS, RANK_OF_CURRENT, dl_size, name_size, pc_name_size ;
    MPI_Status status;
    int int_n[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    char nam[15];
    char my_name[20] = "My name is Mykola";
    int llwn;


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &NUMBER_OF_PROCS);
    MPI_Comm_rank(MPI_COMM_WORLD, &RANK_OF_CURRENT);

    if (NUMBER_OF_PROCS != 4)
    {
        if (RANK_OF_CURRENT == 0)
                  printf("Помилка, Встановіть 4 процесса");
        MPI_Barrier(MPI_COMM_WORLD);
        MPI_Finalize();
        return -1;
    }
    switch(RANK_OF_CURRENT){
        case 2:

	    dl_size = (int) sizeof(int_n) / sizeof(int);


	    MPI_Send(&dl_size,1,MPI_INT,0,1,MPI_COMM_WORLD);
int i;
            for(i = 0; i<3; i++){
                MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
                if (status.MPI_TAG == 4){
                    int size;
                   MPI_Recv(&size,1,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
                    printf("Потік 2: Повернено в мастер з потоку 0 розмір масиву - %d\n",size);
                    MPI_Send(&int_n,size,MPI_INT,0,7,MPI_COMM_WORLD);
                    for (int z = 0; z < size; z++) {
                        printf("%d",int_n[z]);
                    }
                }
                if  (status.MPI_TAG == 5){

                    int size;
                    MPI_Get_count(&status,MPI_CHAR,&size);
                    char res[size];
                    MPI_Recv(&res,size,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
                    printf("Потік 2: Повернено в мастер з потоку 1 - %s \n",res);
                }
                 if  (status.MPI_TAG == 6){

                     int size;
                     MPI_Get_count(&status,MPI_CHAR,&size);
                     char res[size];
                   MPI_Recv(&res,size,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
                    printf("Потік 2: Повернено в мастер з потоку 3 - %s  \n",res);
}
            }
            break;
        case 0: {

            int size;

            MPI_Recv(&size, 1, MPI_INT, 2, 1, MPI_COMM_WORLD, &status);
            printf("Потік 0: Отримано довжину Int масиву - %d  \n", size);
            MPI_Send(&size, 1, MPI_INT, 2, 4, MPI_COMM_WORLD);
            int result[size];
            generateMass(size,result);
            MPI_Send(&result, size, MPI_INT, 2, 7, MPI_COMM_WORLD);
            printf("Потік 0: Отримав массив\n");
            break;
        }
        case 1:

            name_size = (int) sizeof(my_name) / sizeof(char );
            printf("Потік 1: моє імя  - %s \n",my_name);
            MPI_Send(&my_name,name_size,MPI_CHAR,2,5,MPI_COMM_WORLD);
            break;
        case 3:
            MPI_Get_processor_name((char *) &nam, &llwn);
            pc_name_size = (int) sizeof(nam) / sizeof(char );
	        printf("Потік 3: імя процессора - %s \n",nam);
            MPI_Send(&nam,pc_name_size,MPI_CHAR,2,6,MPI_COMM_WORLD);
            break;
    }
    MPI_Finalize();
    return 0;
}
