//
// Created by daniele on 9/27/19.
//

#include "weighted_median.h"
#include "sum.h"
#include "sort.h"

/**
 * algoritmo di risoluzione del problema della mediana inferiore pesata
 * @param ptr array di cui trovare la mediana inferiore pesata
 * @param size dimensione dell'array
 * @return la mediana inferiore pesata
 */
double weighted_median_sort(double *ptr, int size){
    double W = sum_partitions(ptr, 0, size-1);
    sort(ptr, size);
    double sum = 0;
    for (int i=0; i<size; i++){
        sum += ptr[i];
        if (sum >= W/2){
            return ptr[i];
        }
    }
    return -1;
}