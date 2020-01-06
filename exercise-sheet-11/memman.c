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
    srand(time(NULL));

    for (p = 0; p < PG_TABLE_SIZE; ++p)
    {
        int pid = rand() % PROCESSES;
        int pnr = rand() % FRM_PER_PRC;
        int frm = pid * FRM_PER_PRC + pnr;

        table[p].pnr = pnr;
        table[p].pid = pid;
        table[p].fnr = frm;

        if (table[p].fnr > LIMIT)
            return -1;
        
        ram[table[p].fnr + BASE].data[0] = rand();
    }

    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);

    for (p = 0; p < PROCESSES; ++p)
    {
        for (a = 0; a < FRM_PER_PRC; ++a)
        {
            for (i = 0; i < PG_TABLE_SIZE; i++)
            {
                if (table[i].pid == p && table[i].pnr == a)
                {
                    int fnr = table[i].fnr, data;

                    if (fnr > LIMIT)
                        return -1;

                    data = ram[fnr + BASE].data[0];
                    /* ... */
                    break;
                }
            }
        }
    }

    gettimeofday(&tv2, NULL);
    printf ("Total time = %f seconds\n",
        (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
        (double) (tv2.tv_sec - tv1.tv_sec)
    );

    return 0;
}