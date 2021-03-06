//
// Created by daniele on 10/17/2019.
//

#include "sort.h"

void sort (double *ptr, int size){
    mergesort(ptr, 0, size-1, size);
}

void merge (double *ptr, int p, int q, int r, int size){
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

void mergesort (double *ptr, int p, int q, int size) {
    if (p < q) {
        int r = p + (q - p) / 2;
        mergesort(ptr, p, r, size);
        mergesort(ptr, r + 1, q, size);
        merge(ptr, p, q, r, size);
    }
}