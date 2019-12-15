#include <stdio.h>
#include <stdlib.h>
#include "weighted_median.h"
#include "algorithm.h"
#include "analisi_stima_dei_tempi.h"
#define TOLLERANZA 0.05
#define VARIANZA 0.10
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

    void (*p[2]) (double* array, long size, double *arrayToCopy);
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

    FILE *file = fopen("output", "w");
    fprintf(file, "size\ttempo\tdelta\n");


    void (*p[2]) (double* array, long size, double *arrayToCopy);
    p[0]=prepara;
    p[1]=start_algorithm;
    long max_input_size = 10000;
    long step = 100;

    double *array = malloc(max_input_size*sizeof(double));
    double *array_to_copy = malloc(max_input_size*sizeof(double));

    for (long size = 1; size<max_input_size; size+=step){
        double seed = 133769420;
        popola_array(array, size, &seed);
        prepara(array_to_copy, size, array);

        misurazione(p, 2, array, size, array_to_copy,
                get_t_min(result, TOLLERANZA), 5, 1.64, VARIANZA, &seed, file);
    }
    fclose(file);
}

//calcolo_dei_tempi(start_algorithm, array, read, calcola_rip(array, read, get_t_min(result, TOLLERANZA)));
//printf("rip: %lf\n", calcola_rip(array, read, get_t_min(result, TOLLERANZA)));
//printf("tempo medio netto: %lf\n", tempo_medio_netto(p, 2, array, size, array_to_copy, get_t_min(result, TOLLERANZA)));
/*printf("rip: %lf\n", calcola_rip(p, 2, array, read, get_t_min(result, TOLLERANZA)));*/