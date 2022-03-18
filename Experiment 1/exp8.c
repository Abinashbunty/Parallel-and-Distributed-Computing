#include <stdio.h>
#include <omp.h>

int main(){
	int n, i;
	printf("Enter the number of iterations:\n");
	scanf("%d", &n);

	#pragma omp parallel
	#pragma omp for
	for (i=0;i<n;i++){
		printf("Checking parallelism of FOR loop in OpenMP. \n");
	}

	return 0;
}