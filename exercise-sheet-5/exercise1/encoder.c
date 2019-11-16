#include "./code_transfer.h"

void fnc(int *v)
{
    *v += 42;
    return;
}

unsigned copyToMem(byte *source, byte **dest)
{
    unsigned size = 0;
    const byte rts = RTS;

    while (memcmp(source, &rts, 1))
    {
        source++;
        ++size;
    }

    source -= ++size; /* wieder zurücksetzen */

    *dest = (byte *)malloc(size);

    memcpy(*dest, source, size);

    return size;
}

int main (int argc, char **argv)
{
    char *fileName;
    FILE *outputFile;
    byte *codeArray;
    unsigned size;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    fileName = argv[1];
    size = copyToMem((byte *)fnc, &codeArray);
    outputFile = fopen(fileName, "w+");
    fwrite(codeArray, sizeof(byte), size, outputFile);
    free(codeArray);
    fclose(outputFile);

    printf("Successfully encoded %d bytes of executable code to binary file %s\n",
        size, fileName);

    return 0;
}