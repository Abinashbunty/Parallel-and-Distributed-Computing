#include <stdio.h>
#include <omp.h>

int biggest(int a[], int no_of_elements){
	int max = a[0];
	int i;
	for(i=1;i<no_of_elements;i++){
		if(a[i]>max)
			max = a[i];
	}

	return max;
}

int smallest(int a[], int no_of_elements){
	int min = a[0];
	int i;
	for(i=1;i<no_of_elements;i++){
		if(a[i]<min)
			min = a[i];
	}

	return min;	
}

int factorial(int no_of_elements){
	int i, f = 1;
	for(i=no_of_elements;i>1;i--)
		f = f * i;

	return f;
}

void fibonacci(int no_of_elements){
	int num1 = 0, num2 = 1;
	printf("%d | %d ", num1, num2);
	int i, s = 0;
	for(i=3;i<=no_of_elements;i++){
		s = num1+num2;
		printf("| %d ", s);
		num1 = num2;
		num2 = s;
	}
	printf("\n");
}

int main(){
	int n;
	printf("Enter the number of elements: \n");
	scanf("%d", &n);
	int i;
	printf("Enter elements into the array:\n");
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);

	printf("-------------------------------------\n");
	printf("|         Sequential Outputs        |\n");
	printf("-------------------------------------\n");
	printf("Biggest number in the array  = %d\n", biggest(arr, n));
	printf("Smallest number in the array = %d\n", smallest(arr, n));
	printf("Factorial of given number    = %d\n", factorial(n));
	printf("Fibonacci series upto %d numbers is as follows: \n", n);
	fibonacci(n);
	printf("-------------------------------------\n");
	printf("-------------------------------------\n");

	printf("-------------------------------------\n");
	printf("|          Parallel Outputs         |\n");
	printf("-------------------------------------\n");
	#pragma omp parallel
	{
		#pragma omp sections
		{
			#pragma omp section
			printf("Biggest number in the array  = %d\n", biggest(arr, n));
			
			#pragma omp section
			printf("Smallest number in the array = %d\n", smallest(arr, n));

			#pragma omp section
			printf("Factorial of given number    = %d\n", factorial(n));

			#pragma omp section
			printf("Fibonacci series upto %d numbers is as follows: \n", n);
		}
	}

	printf("-------------------------------------\n");
	printf("-------------------------------------\n");
	printf("           End of Program            \n");
	printf("-------------------------------------\n");

	return 0;
}