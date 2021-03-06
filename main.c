#include <stdio.h>
#include <stdlib.h>
#include "weighted_median.h"
#include "algorithm.h"
#include "analisi_stima_dei_tempi.h"

#define TOLLERANZA 0.02
#define VARIANZA 0.02
#define NUMERO_CAMPIONI 10
#define ZALPHA 2.33

void start_project();
void start_testing();

int main(int argc, char **argv){
    start_project();

    //rimuovere il commento per far partire il testing
    //start_testing(atoi(argv[1])); //prende un valore da standard input per la dimensione dell'array da utilizzare
    return 0;
}

/**
 * metodo che fa partire il progetto
 */
void start_project() {
    int size = 1;
    double *array = malloc(size*sizeof(double));
    int read = 0;
    while (scanf("%lf%*[ ,]", &array[read]) >= 1) {
        if(++read == size) {
            size *= 2;
            array = realloc(array, size*sizeof(double));
        }
    }
    start_algorithm_print(array, read);
}

/**
 * metodo che far partire il testing del progetto
 * @param size_input dimensione dell'array
 */
void start_testing(int size_input){
    double result = granularita();

    void (*p[2]) (double*, int, double*);
    p[0]=prepara;
    p[1]=start_algorithm;

    int size = size_input;
    double *array = malloc(size*sizeof(double));

    double seed = 133769420;
    prepara(array, size, &seed);

    misurazione(p, 2, array, size,
            get_t_min(result, TOLLERANZA), NUMERO_CAMPIONI, ZALPHA, VARIANZA, &seed);
}