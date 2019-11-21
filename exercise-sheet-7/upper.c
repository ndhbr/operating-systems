#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

void strToUpper(char *sPtr)
{
    while (*sPtr != '\0')
    {
        *sPtr = toupper((unsigned char)*sPtr);
        sPtr++;
    }
}

int main(int argc, char **argv)
{
    int child[2];
    pipe(child);

    if (fork() == 0) // child
    {
        char buff[64];

        read(child[0], buff, 64);
        close(child[1]);
        strToUpper(buff);
        printf("Received: %s\n", buff);
    }
    else // parent
    {
        FILE *file;
        char buff[64];

        file = fopen("testDatei.txt", "r");
        fscanf(file, "%s", buff);

        close(child[0]);
        write(child[1], buff, 64);

        fclose(file);
    }

    return 0;
}