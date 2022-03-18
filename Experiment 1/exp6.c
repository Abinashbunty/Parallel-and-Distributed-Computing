#include <stdio.h>
#include <omp.h>

int main(){
	int a[10];

	omp_set_num_threads(4);
	#pragma omp parallel
	{
		int thread_id = omp_get_thread_num();
		for(int i=thread_id;i<10;i=i+omp_get_num_threads()){
			a[i] = i*i + 1;
			printf("Thread ID: %d\n", omp_get_thread_num());
			printf("%d\n\n", a[i]);
		}
	}

	return 0;
}