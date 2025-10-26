#include <stdio.h>
#include <stdlib.h>

int main() {
	long *arr = malloc(5 * sizeof(long)); /* allocate memory for 5 integers */

	for (int i = 0; i < 5; i++)
	{
		arr[i] = rand(); /* init array */	
	}

	for (int i = 0; i < 5; i++)
	{
		printf("arr[%d]: %p\n",i,&arr[i]);
	}

	free(arr);
}

