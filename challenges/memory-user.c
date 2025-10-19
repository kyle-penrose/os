#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int mb = (argc > 1) ? atoi(argv[1]) : 10;
    size_t bytes = (size_t)mb * 1024 * 1024;

    char *p = malloc(bytes);

    printf("pid: %ld\n", (long)getpid());

    if (!p) {
        printf("Allocation failed.\n");
        return 1;
    }

    while (1) {
        for (size_t i = 0; i < bytes; i++) {
            p[i]++;
        }
    }

    // unreachable, but keeps the compiler happy
    free(p);
    return 0;
}


