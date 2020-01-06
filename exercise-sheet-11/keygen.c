#define PROCESSES 5
#define FRM_PER_PRC 500
#define PG_TABLE_SIZE 100
#define FRAME_SIZE 512
#define BASE 0
#define LIMIT 2500

struct frame
{
    char data[FRAME_SIZE];
} ram[LIMIT + BASE];

struct page
{
    int pnr, pid, fnr;
} table[PG_TABLE_SIZE];

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

int main (int argc, char **argv)
{
    register int p, a, i;

    for (p = 0; p < PROCESSES; ++p)
    {
        for (a = 0; a < FRM_PER_PRC; ++a)
        {
            printf("%d\n", p * FRM_PER_PRC + a);
        }
    }

    return 0;
}