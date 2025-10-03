#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Process PID = %d\n", getpid());
	fork();
	printf("After fork, PID = %d\n", getpid());
	return 0;
}
