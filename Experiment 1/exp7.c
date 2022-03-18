#include <stdio.h>
#include <omp.h>

int main(){
	#pragma omp parallel
	{
		int n = omp_in_parallel();
		if(n==1)
			printf("You are in parallel zone\n");
		else
			printf("You are in sequence zone\n");
	}

return 0;

}