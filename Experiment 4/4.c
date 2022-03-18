#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv){
	int i, j, k, p;
	int a[1000], b[2500], c[4], myrank, res, x, y;
	int interval, sum = 0;

	for(i=0;i<1000;i++)
		a[i] = i;

	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	MPI_Scatter(a, 250, MPI_INT, b, 250, MPI_INT, 0, MPI_COMM_WORLD);

	res = 0;
	for(i=0;i<250;i++)
		res = res + b[i];

	MPI_Gather(&res, 1, MPI_INT, c, 1, MPI_INT, 0, MPI_COMM_WORLD);

	int final = 0;
	if(myrank==0){
		for(i=0;i<4;i++){
			printf("The sum that is calculated in core %d is %d \n", (i+1), c[i]);
			final = final + c[i];
		}
		printf("The final sum = %d\n", final);
	}

	MPI_Finalize();
	return 0;
}