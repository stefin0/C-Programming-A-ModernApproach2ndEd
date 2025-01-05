/*
5. Write a program named sum.c that adds up its command-line arguments, which
are assumed to be integers. Running the program by typing
sum 8 24 62
should produce the following output:
Total: 94
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int total = 0;

    for (int i = 1; i < argc; i++) {
        total += atoi(argv[i]);
    }

    printf("Total: %d\n", total);

    return 0;
}
