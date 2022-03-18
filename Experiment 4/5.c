#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#define maxsize 1000

int main(int argc, char **argv){
	double t1, t2;
	int myid, numprocs;
	int low, high, myresult=0, result;
	char fn[255];

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	t1 = MPI_Wtime();
	int i, x, data[1000];
	FILE *fptr;
	fptr = fopen("numbers.txt", "r");
	if(fptr==NULL){
		printf("Error!\n");
		exit(1);
	}

	for(i=0;i<1000;i++)
		fscanf(fptr, "%d", &data[i]);
	fclose(fptr);

	MPI_Bcast(data, maxsize, MPI_INT, 0, MPI_COMM_WORLD);

	x = maxsize/numprocs;
	low = myid * x;
	high = low + x;
	for(i=low;i<high;i++)
		myresult = myresult + data[i];
	printf("Obtained %d from %d\n",myresult, myid);

	MPI_Reduce(&myresult, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if(myid==0)
		printf("Sum = %d\n", result);

	t2 = MPI_Wtime();

	MPI_Finalize();
	printf("Time taken = %.7f\n", (t2-t1));
	return 0;
}