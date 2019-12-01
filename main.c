#include <stdio.h>
#include <stdlib.h>
#include "weighted_median.h"
#include "algorithm.h"

int main(int argc, char **argv) {
    //inserimento input
    int size = 1;
    double *array = malloc(size*sizeof(double));
    int read = 0;
    while (scanf("%lf%*[ ,]", &array[read]) >= 1) {
        if(++read == size) {
            size *= 2;
            array = realloc(array, size*sizeof(double));
        }
    }

    /*for (int i =0; i<read; i++){
        printf("%lf ", array[i]);
    }*/
    //printf("\n");
    start_algorithm(array, read);

    return 0;
}