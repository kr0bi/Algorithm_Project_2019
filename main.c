#include <stdio.h>
#include <stdlib.h>
#include "weighted_median.h"
#include "algorithm.h"
#include "analisi_stima_dei_tempi.h"
#define TOLLERANZA 0.02

void start_project();

int main(int argc, char **argv) {
    //double result = granularita();
    //printf("granularita: %lf\ntmin: %lf\n",result,get_t_min(result, TOLLERANZA));
    //inserimento input
    start_project();

    return 0;
}

void start_project() {
    double result = granularita();
    int size = 1;
    double *array = malloc(size*sizeof(double));
    int read = 0;
    while (scanf("%lf%*[ ,]", &array[read]) >= 1) {
        if(++read == size) {
            size *= 2;
            array = realloc(array, size*sizeof(double));
        }
    }

    calcolo_dei_tempi(array, read, calcola_rip(array, read, get_t_min(result, TOLLERANZA)));
    //printf("rip: %lf\n", calcola_rip(array, read, get_t_min(result, TOLLERANZA)));
    //start_algorithm(array, read);
}

/*for (int i =0; i<read; i++){
       printf("%lf ", array[i]);
   }*/
//printf("\n");