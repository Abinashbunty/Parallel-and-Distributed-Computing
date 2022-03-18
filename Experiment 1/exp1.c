#include <stdio.h>
#include <omp.h>
int main(){
	printf("\nHello World\n");
	
	#pragma omp parallel
	{
	printf("\nHello World\n");
	printf("\nHello World\n");
}

return 0;
}