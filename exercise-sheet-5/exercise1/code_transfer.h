#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#define RTS ((byte) 0xc3)

typedef void (*modification)(int *);
typedef unsigned char byte;

void fnc(int *);
unsigned copyToMem(byte *source, byte **dest);
modification restoreFromFile(const char *fileName, int bytes);
