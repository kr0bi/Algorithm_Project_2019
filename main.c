#include <stdio.h>
#include <stdlib.h>
#include "weighted_median.h"
#include "algorithm.h"

int main(int argc, char **argv) {
    //controllo input
    if (argc == 0){

    }

    //inserimento input
    int size = 1;
    double *array = malloc(size*sizeof(double));
    int read = 0;
    while (scanf("%lf%*[,]", &array[read]) == 1) {
        if(++read == size) {
            size += 1;
            array = realloc(array, size*sizeof(double));
        }
    }
    //inizio algoritmo
    //double array[] = {0.1 , 0.35 , 0.05, 0.1, 0.15 , 0.05, 0.2 };
    //int size2 = (int)(sizeof(array)/sizeof(array[0]));
    start_algorithm(array, size);
    return 0;
}