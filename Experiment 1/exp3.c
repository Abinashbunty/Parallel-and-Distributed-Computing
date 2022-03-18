#include <stdio.h>
#include <omp.h>

int main(){
	printf("Hello World\n");
	int n = omp_get_max_threads();
	printf("Max threads = %d\n", n);

return 0;
}