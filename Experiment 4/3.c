#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv){
	int n, i;
	int size, rank;

	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	MPI_Barrier(MPI_COMM_WORLD);

	if(rank==0){
		int n, i;
	    printf("Enter the number of elements:\n");
	    scanf("%d", &n);
	    int arr[n];
	    printf("Enter the array:\n");
	    for(i=0;i<n;i++)
		    scanf("%d", &arr[i]);
		printf("\n");
		printf("The resultant array is:\n");
		for(i=0;i<n;i++)
			printf("%d ", (arr[i]*arr[i]));
		printf("\n");
	}

	MPI_Barrier(MPI_COMM_WORLD);

	MPI_Finalize();
	return 0;
}