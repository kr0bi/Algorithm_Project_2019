#include <stdio.h>
#include <stdlib.h>
#include "weighted_median.h"
#include "algorithm.h"
#include "analisi_stima_dei_tempi.h"
#define TOLLERANZA 0.02
#define NUMBER_OF_ARGUMENTS 2

void start_project();

int main(int argc, char **argv) {
    //long res = granularita2();
    //double result = granularita();
    //printf("granularita: %lf\ntmin: %lf\n",result,get_t_min(result, TOLLERANZA));
    //printf("granularita2: %ld\n",res);
    //printf("granularita: %ld\ntmin: %d\n",res,get_t_min2(res, TOLLERANZA));
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

    void (*p[2]) (double* array, int size, double *arrayToCopy);
    p[0]=prepara;
    p[1]=start_algorithm;

    //calcolo_dei_tempi(array, read, calcola_rip(array, read, get_t_min(result, TOLLERANZA)));
    //printf("rip: %lf\n", calcola_rip(array, read, get_t_min(result, TOLLERANZA)));

    printf("rip: %lf\n", calcola_rip(p, 2, array, read, get_t_min(result, TOLLERANZA)));

    //start_algorithm_print(array, read);
}

/*for (int i =0; i<read; i++){
       printf("%lf ", array[i]);
   }*/
//printf("\n");