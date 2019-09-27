//
// Created by daniele on 9/27/19.
//

#include "weighted_median.h"
#include "select.h"
#include "sum.h"

double weighted_median_sort(Array *ptr){

}

double weighted_median_optimal(Array *ptr, int p, int r, double w){
    if (r==p){
        return ptr->array[p];
    }
    if (r-p == 1){
        if (ptr->array[p] >= ptr->array[r]){
            return ptr->array[p];
        } else {
            return ptr->array[r];
        }
    }
    int q = partition(ptr, p, r);
    double wl = sum_partitions(ptr, p, q-1);
    double wg = sum_partitions(ptr, q+1, r);

    if (wl < w/2 && wg < w/2 ){
        return ptr->array[q];
    } else {
        if (wl > wg){
            weighted_median_optimal(ptr, p, q, w-wg);
        } else {
            weighted_median_optimal(ptr, q, r, w+wl);
        }
    }

}
