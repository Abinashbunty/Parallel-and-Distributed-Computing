#include <stdio.h>
#include <omp.h>

int main(){
	printf("\nHello World\n");
	int a = omp_get_num_threads();
	printf("The number of threads in sequence: %d\n", a);
	#pragma omp parallel
	{
	printf("Hello World\n");
	printf("Hello World\n");

	int n = omp_get_num_threads();
	printf("The number of threads in parallel: %d\n", n);
	
	printf("\n\n");
}
return 0;
}