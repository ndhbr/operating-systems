#include <stdio.h>
#include <stdlib.h>


// Valgrind test
int main(int argc, char **argv)
{
    char *p = malloc(1);
    *p = 'a';
    char c = *(p + 1);

    printf("\n[%c]\n", c);

    free(p);

    return 0;
}