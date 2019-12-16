#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"

#define SIZE 8


int main(int argc, char **argv)  {
    int i, j, ts, tp; 
    matrix *m1 = createMatrix(SIZE, SIZE),
           *m2 = createMatrix(SIZE, SIZE), *p1, *p2;
     srand(time(NULL));     
     for (i = 0;  i < SIZE;  ++i)
        for (j = 0;  j < SIZE;  ++j)  {
           setValue(m1, i, j, rand() % 10 / (rand() % 10 + 1.0));
           setValue(m2, i, j, rand() % 10 / (rand() % 10 + 1.0));  
        }
    p1 = mult(m1, m2);
    printf("A:\n");
    printMatrix(m1); 
    printf("B:\n");
    printMatrix(m2);
    printf("AxB:\n");
    printMatrix(p1);
    printf("A'xB':\n");
    p2 = forkmult(m1, m2);  
    printMatrix(p2);
    return 0;        
}
