#include <stdio.h>
#include <setjmp.h>
#include <time.h>
#include <stdbool.h>

jmp_buf buf; // Define a global variable to hold the jump buffer
clock_t start[3];
clock_t end[4];
int i;

void func1() {
    printf("In func1\n");
    start[0] = clock();
    longjmp(buf, 1); // Jump to the location saved by setjmp with value 1
}

void func2() {
    printf("In func2\n");
    start[1] = clock();
    longjmp(buf, 2); // Jump to the location saved by setjmp with value 2
}

void func3() {
    printf("In func3\n");
    start[2] = clock();
}

int main() {
    int val = setjmp(buf); // Save the current execution context in buf                       
    end[val] = clock();
    if (val == 0) {
        func1(); // Initially, jump to func1
    } else if (val == 1) {
        func2(); // Return here after jumping from func1
    } else if (val == 2) {
        func3(); // Return here after jumping from func2
    }
    
    end[3] = clock();
    for (i = 0; i < 3; i++)
    {
        printf("Switch %d took %lf microseconds.\n", i+1, (double)(end[i+1] - start[i]) * 1e6 / CLOCKS_PER_SEC);
    }
    return 0;
}
