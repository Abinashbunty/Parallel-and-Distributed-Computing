#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <stdbool.h>

bool prime(int n){
	int i;
	int c = 0;
	for(i=2;i<=n/2;i++){
		if(n%2==0)
			c = c + 1;
	}

	if(c==0)
		return true;
	else
		return false;
}

int main(){
	bool result = false;
	int num, i;
	int count = 0; // Number of prime numbers
	int list_size;
	printf("Enter number of random numbers for prime check: \n");
	scanf("%d", &list_size);

	#pragma omp parallel
	{
		for(i=1;i<=list_size;i++){
			num = rand();
			result = prime(num);
			if(result==true){
				count = count + 1;
				printf("-----------------------------------\n");
				printf("%d is a prime number from the list.\n", num);
				printf("Core %d is the one that performed the check.\n", omp_get_thread_num());
				printf("-----------------------------------\n");
			}

			else
				printf("%d is not a prime number.\n", num);
		}
	}

	printf("Total number of prime numbers present in the list = %d\n", count);

	return 0;
}