//
// Created by daniele on 9/27/19.
//

#include <values.h>
#include "select.h"

int partition (Array* a, int l, int r){
    double x = a->array[r];
    int i = l;
    for (int j=l; j<r; j++){
        if (a->array[j] <= x){
            swap(&a->array[i], &a->array[j]);
            i++;
        }
    }
    swap(&a->array[i], &a->array[r]);
    return i;
}

double kthSmallest(Array* a, int l, int r, int k){
    if (k>0 && k<=(r-l+1)){

        int index = partition(a, l, r);

        if (index - l == k - 1){
            return a->array[index];
        }
        if (index - l > k - 1){
            return kthSmallest(a, l, index-1, k);
        }
        return kthSmallest(a, index+1, r, k-index+l-1);
    }
    return -1;
}

void swap (double* a, double *b){
    double temp = *b;
    *b = *a;
    *a = temp;
}
