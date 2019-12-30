//
// Created by daniele on 11/28/19.
//
#include <stdio.h>
#include "weighted_median.h"

/**
 * fa partire l'algoritmo risolutivo e stampa il risultato
 * @param array
 * @param size
 */
void start_algorithm_print(double* array, int size){
    double med_sort = weighted_median_sort(array, size);
    printf("%.15f\n", med_sort);
}

/**
 * fa partire l'algoritmo risolutivo senza stamparne il risultato
 * @param array
 * @param size
 */
void start_algorithm(double* array, int size){
    double med_sort = weighted_median_sort(array, size);
    //printf("%.8f\n", med_sort);
}
