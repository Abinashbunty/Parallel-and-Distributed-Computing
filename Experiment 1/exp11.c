#include <stdio.h>
#include <omp.h>

int main(){
	int i;
	int sum = 0;
	// #pragma omp parallel
	#pragma omp parallel for reduction(+:sum)
   	for(i=1;i<=100;i++)
   		sum = sum + i*i;

   	printf("-----------------------------------------------------------\n");
   	printf("The sum of squares of the 1st 100 natural numbers = %d\n", sum);
   	printf("-----------------------------------------------------------\n");
	return 0;
}