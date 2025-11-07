#include <stdio.h>
#include <stdlib.h>

int main() {
	int *arr = malloc(5 * sizeof(int)); /* allocate memory for 5 integers */
    int stack_var = 1;
	for (int i = 0; i < 5; i++)
	{
		arr[i] = i*5; /* init array */	
	}

	for (int i = 0; i < 5; i++)
	{
		printf("arr[%d]:%d, at %p\n",i,arr[i],&arr[i]);
	}

    printf("stack variable:%d at %p\n",stack_var,&stack_var);

	free(arr);
}

