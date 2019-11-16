#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Valgrind test
int main(int argc, char **argv)
{
    char *cp;
    cp = (char *)malloc(50);
    cp = "ohohoh";
    // strcpy(cp, "ohohoh\0");

    printf("String ist: %s\n", cp);

    free(cp);

    return 0;
}