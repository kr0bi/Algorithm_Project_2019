#include <stdio.h>
#include <stdlib.h>
#include "weighted_median.h"
#include "algorithm.h"
#include "analisi_stima_dei_tempi.h"
#define TOLLERANZA 0.02
#define NUMBER_OF_ARGUMENTS 2

void start_project();
void start_testing();

int main(int argc, char **argv) {
    //long res = granularita2();
    //double result = granularita();
    //printf("granularita: %lf\ntmin: %lf\n",result,get_t_min(result, TOLLERANZA));
    //printf("granularita2: %ld\n",res);
    //printf("granularita: %ld\ntmin: %d\n",res,get_t_min2(res, TOLLERANZA));
    //inserimento input
    //start_project();
    start_testing();
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
    double *array_to_copy = malloc(read*sizeof(double));
    prepara(array, read, array_to_copy);
    //calcolo_dei_tempi(start_algorithm, array, read, calcola_rip(array, read, get_t_min(result, TOLLERANZA)));
    //printf("rip: %lf\n", calcola_rip(array, read, get_t_min(result, TOLLERANZA)));
    tempo_medio_netto(p, 2, array, read, array_to_copy, get_t_min(result, TOLLERANZA));
    /*printf("rip: %lf\n", calcola_rip(p, 2, array, read, get_t_min(result, TOLLERANZA)));*/

    //start_algorithm_print(array, read);
}

void start_testing(){
    double result = granularita();

    int size = 1000;
    double *array = malloc(size*sizeof(double));
    double seed = 133769420;
    popola_array(array, size, &seed);
    /*for (int i =0; i<size; i++){
        printf("%lf ", array[i]);
    }
    printf("\n");*/
    void (*p[2]) (double* array, int size, double *arrayToCopy);
    p[0]=prepara;
    p[1]=start_algorithm;
    double *array_to_copy = malloc(size*sizeof(double));
    prepara(array, size, array_to_copy);
    //calcolo_dei_tempi(start_algorithm, array, read, calcola_rip(array, read, get_t_min(result, TOLLERANZA)));
    //printf("rip: %lf\n", calcola_rip(array, read, get_t_min(result, TOLLERANZA)));
    //tempo_medio_netto(p, 2, array, size, array_to_copy, get_t_min(result, TOLLERANZA));
    /*printf("rip: %lf\n", calcola_rip(p, 2, array, read, get_t_min(result, TOLLERANZA)));*/

    misurazione(p, 2, array, size, array_to_copy, get_t_min(result, TOLLERANZA), 5, 2.33, TOLLERANZA, &seed);
}