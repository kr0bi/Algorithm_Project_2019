//
// Created by daniele on 10/17/2019.
//

#include "sort_modifica.h"

void sort (double *ptr, double *fine_ptr){
    int p = 0;
    int q = fine_ptr-ptr;
    mergesort(ptr, p, q);
}

void merge (double *ptr, int p, int q, int r){
    Array *B = newArrayLength(q-p);
    int i = p;
    int j = r + 1;
    for (int k = p; k <= q; k++){
        if (i<=r && j<=q) {
            if (ptr[i] <= ptr[j]) {
                B->array[k] = ptr[i];
                i = i + 1;
            } else if (ptr[i] > ptr[j]) {
                B->array[k] = ptr[j];
                j = j + 1;
            }
        } else if (i<=r){
            B->array[k]=ptr[i];
            i=i+1;
        } else if (j<=q){
            B->array[k]=ptr[j];
            j=j+1;
        }
    }
    for (int k = p; k<=q; k++){
        ptr[k]=B->array[k];
    }


}

void mergesort (double *ptr, int p, int q) {
    if (p < q) {
        int r = p + (q - p) / 2;
        mergesort(ptr, p, r);
        mergesort(ptr, r + 1, q);
        merge(ptr, p, q, r);
    }
}