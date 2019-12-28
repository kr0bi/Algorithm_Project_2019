//
// Created by daniele on 9/27/19.
//
#include "sum.h"
double sum_partitions(double *ptr, int p, int q){
    double sum = 0.0;
    for (int i = p; i<=q; i++){
        sum += ptr[i];
    }
    return sum;
}
