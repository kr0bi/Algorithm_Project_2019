//
// Created by daniele on 9/27/19.
//

#include "sort.h"
#include <stdlib.h>

void sort_array(double *ptr, int size){
    int p = 0;
    int q = size-1;
    mergesort_2(ptr, p, q, size);
}

void merge_2 (double *ptr, int p, int q, int r, int size){
    double B[size];
    int i = p;
    int j = r + 1;
    for (int k = p; k <= q; k++){
        if (i<=r && j<=q) {
            if (ptr[i] <= ptr[j]) {
                B[k] = ptr[i];
                i = i + 1;
            } else if (ptr[i] > ptr[j]) {
                B[k] = ptr[j];
                j = j + 1;
            }
        } else if (i<=r){
            B[k]=ptr[i];
            i=i+1;
        } else if (j<=q){
            B[k]=ptr[j];
            j=j+1;
        }
    }
    for (int k = p; k<=q; k++){
        ptr[k]=B[k];
    }


}

void mergesort_2 (double *ptr, int p, int q, int size){
    if (p<q){
        int r = p+(q-p)/2;
        mergesort_2(ptr, p, r, size);
        mergesort_2(ptr, r + 1, q, size);
        merge_2(ptr, p, q, r, size);
    }
}