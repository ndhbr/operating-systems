#include "code_transfer.h"

modification restoreFromFile(const char *fileName, int bytes)
{
    FILE *inputFile = fopen(fileName, "r");
    byte *dataArray = (byte *)malloc(bytes);
    byte *exe;
    fread(dataArray, bytes, sizeof(byte), inputFile);

    exe = (byte *)mmap(0, bytes, PROT_EXEC | PROT_WRITE | PROT_READ,
                MAP_PRIVATE | MAP_ANON, -1, 0);
    memcpy(exe, dataArray, bytes);

    free(dataArray);
    /*fclose(inputFile);*/

    mprotect(exe, bytes, PROT_EXEC | PROT_READ);

    return (modification)exe;
}

int main(int argc, char **argv)
{
    const char *fileName;
    int originalValue, resultValue;

    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <file_name>"\
                        " <file_size> <input>\n", argv[0]);
        return 1;
    }

    fileName = argv[1];
    originalValue = atoi(argv[3]);
    resultValue = originalValue;

    modification fnc = restoreFromFile(fileName = argv[1], atoi(argv[2]));
    (*fnc)(&resultValue);

    printf( "The result of applying %s"\
            " to %d is $d\n", argv[1], originalValue, resultValue);

    return 0;
}