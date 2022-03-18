/*

Program to check and print which iteration is done by which thread ID


#include <stdio.h>
#include <omp.h>
#include <time.h>

int main(){
	int i = 0;
	// clock_t start_clock = clock();
	#pragma omp parallel
	{
		#pragma omp for
		for(i=0;i<20;i++){
			printf("Iteration no. = %d\n", i+1);
			printf("Thread ID: %d\n", omp_get_thread_num());
		}		
	}

	return 0;
}

*/

/*

Program using dynamic memory allocation


#include <stdio.h>
#include <omp.h>


int main(){
	printf("Enter number of rows and columns in the matrix:\n");
	int r, c;
	scanf("%d%d", &r, &c);

	int a[r][c];
	int b[c][r];
	int i, j;

	printf("Enter the elements into the matrix row-wise\n");
	printf("-------------------------------------------\n");

	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			a[i][j] = i + j;
		}
	}

	printf("Elements are already entered for you :-P \n\n");
	double start0 = omp_get_wtime();

	for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				b[i][j] = a[j][i];
			}
		}

	double stop0 = omp_get_wtime();

	double start1 = omp_get_wtime();
	#pragma omp parallel
	{
		#pragma omp for
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				b[i][j] = a[j][i];
			}
		}
	}

	double stop1 = omp_get_wtime();

	printf("--------------------------------\n");
	printf("Sequential time = %f\n", (stop0-start0));
	printf("--------------------------------\n");
	printf("Parallel time = %f\n", (stop1-start1));
	printf("--------------------------------\n");
	printf("\n\n");
	
	return 0;
}

*/