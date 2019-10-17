//
// Created by daniele on 9/27/19.
//

#include "sort.h"

void sort_array(Array *ptr){
    int p = 0;
    int q = ptr->size-1;
    mergesort_2(ptr, p, q);
}

void merge_2 (Array *ptr, int p, int q, int r){
    Array *B = newArrayLength(ptr->size);
    int i = p;
    int j = r + 1;
    for (int k = p; k <= q; k++){
        if (i<=r && j<=q) {
            if (ptr->array[i] <= ptr->array[j]) {
                B->array[k] = ptr->array[i];
                i = i + 1;
            } else if (ptr->array[i] > ptr->array[j]) {
                B->array[k] = ptr->array[j];
                j = j + 1;
            }
        } else if (i<=r){
            B->array[k]=ptr->array[i];
            i=i+1;
        } else if (j<=q){
            B->array[k]=ptr->array[j];
            j=j+1;
        }
    }
    for (int k = p; k<=q; k++){
        ptr->array[k]=B->array[k];
    }


}

void mergesort_2 (Array *ptr, int p, int q){
    if (p<q){
        int r = p+(q-p)/2;
        mergesort_2(ptr, p, r);
        mergesort_2(ptr, r + 1, q);
        merge_2(ptr, p, q, r);
    }
}