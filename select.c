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
            printArray(a);
            i++;
        }
    }
    printArray(a);
    swap(&a->array[i], &a->array[r]);
    return i;
}

/**
 * ritorna l'elemento piu' piccolo a quella posizione
 * @param a
 * @param l
 * @param r
 * @param k
 * @return
 */

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

int find_x_in_a(Array *a, double x){
    for (int i=0; i<a->size-1; i++){
        if (a->array[i] == x){
            return i;
        }
    }
    return -999;
}


int partition_select (Array *a, int l, int r){
    double x = kthSmallest(a, l , r, floor((l+r)/2));
    int index = find_x_in_a(a, x);
    swap(&a->array[index], &a->array[r]);
    printArray(a);
    return partition(a,l,r);
}

