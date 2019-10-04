//
// Created by daniele on 9/27/19.
//

#include "weighted_median.h"
#include "select.h"
#include "sum.h"
#include "sort.h"
#include "select.h"

double weighted_median_sort(Array *ptr){
    double W = sum_partitions(ptr, 0, ptr->size-1);
    sort(ptr);
    double sum = 0;
    for (int i=0; i<ptr->size; i++){
        sum += ptr->array[i];
        if (sum > W/2){
            return ptr->array[i];
        }
    }
    return -1;

}
double weighted_median_optimal(Array *ptr){
    int p = 0;
    int r = ptr->size-1;
    double w = sum_partitions(ptr, 0, r);
    return weighted_median_optimal_rec(ptr, p, r, w/2);
}


double weighted_median_optimal_rec(Array *ptr, int p, int r, double target){
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
    int q = partition_select(ptr, p, r);
    printArray(ptr);
    double wl = sum_partitions(ptr, p, q-1);
    double wg = sum_partitions(ptr, q+1, r);

    if (wl < target && wg >= target ){
        return ptr->array[q];
    } else {
        if (wg < target){
            weighted_median_optimal_rec(ptr, q+1, r, target-wg);
        } else {
            weighted_median_optimal_rec(ptr, p, q-1, target);
        }
    }

}
