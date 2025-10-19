#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    char * end;

    if (argc > 1)
    {
        int a = (int)strtol(argv[1], &end, 10);
        printf("Number is %d\n", a);
    }
    else
    {
        printf("No argument given.\n");
    }
}
