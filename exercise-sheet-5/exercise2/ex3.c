#include <stdio.h>
#include <stdlib.h>

// Valgrind test
int main(int argc, char **argv)
{
    char *p = malloc(1);
    *p = 'a';
    
    char c = *p;

    printf("\n[%c]\n", c);

    free(p);

    c = *p;

    return 0;
}