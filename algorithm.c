//
// Created by daniele on 11/28/19.
//
#include <stdio.h>
#include "weighted_median.h"

void start_algorithm(double* array, int size){
    double med_sort = weighted_median_sort(array, size);
    printf("%.8f\n", med_sort);
}