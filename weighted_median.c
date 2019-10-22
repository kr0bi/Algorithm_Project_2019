//
// Created by daniele on 9/27/19.
//

#include "weighted_median.h"
#include "select_miglioramento.h"
#include "sum.h"
#include "sort.h"

double weighted_median_sort(double *ptr, int size){
    double W = sum_partitions(ptr, 0, size-1);
    sort_array(ptr, size);
    double sum = 0;
    for (int i=0; i<size; i++){
        sum += ptr[i];
        if (sum > W/2){
            return ptr[i];
        }
    }
    return -1;

}
double weighted_median_optimal(double *ptr, int size){
    int p = 0;
    int r = size-1;
    double w = sum_partitions(ptr, p, r);
    return weighted_median_optimal_rec(ptr, p, r, floor(w/2.0), floor(w/2.0));
}
double weighted_median_optimal_rec(double *ptr, int p, int r, double targetsx, double targetdx){
    if (r==p){
        return ptr[p];
    }
    if (r-p == 1){
        if (ptr[p] >= ptr[r]){
            return ptr[p];
        } else {
            return ptr[r];
        }
    }
    int q = partition_select(ptr, p, r);
    double wl = sum_partitions(ptr, p, q-1);
    double wg = sum_partitions(ptr, q+1, r);
    //printArray(ptr);
    if (wl <= targetsx && wg < targetdx ){
        return ptr[q];
    } else {
        if (wl > wg){
            weighted_median_optimal_rec(ptr, p, q, targetsx, targetdx-wg);
        } else {
            weighted_median_optimal_rec(ptr, q, r, targetsx-wl, targetdx);
        }
    }
}
