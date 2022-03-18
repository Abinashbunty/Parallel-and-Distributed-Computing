#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
    int n, i, *ptr;
    int sum = 0;

    printf("Enter number of elements: \n");
    scanf("%d", &n);

    ptr = (int*) malloc(n*sizeof(int));
    if(ptr==NULL){
        printf("Memory is not allocated.\n");
        exit(0);
    }

    printf("----------------------------------------\n");
    printf("Elements of array are now being entered.\n");
    printf("----------------------------------------\n");
    #pragma omp parallel
    {
    for(i=1;i<=n;i++)
        *(ptr+i-1) = i*i;

    #pragma omp parallel for reduction(+:sum)
    for(i=0;i<n;i++)
        sum = sum + *(ptr+i);

    }

    printf("---------------------------------\n");
    printf("Sum of %d elements = %d\n\n", n, sum);
    printf("---------------------------------\n");

    free(ptr);
    return 0;
}