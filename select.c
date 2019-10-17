//
// Created by daniele on 9/27/19.
//

#include "select.h"

int partition (Array* a, int l, int r){
    double x = a->array[r];
    int i = l;
    for (int j=l; j<r; j++){
        if (a->array[j] <= x){
            swap(&a->array[i], &a->array[j]);
            //printArray(a);
            i++;
        }
    }
    //printArray(a);
    swap(&a->array[i], &a->array[r]);
    return i;
}

int partition_lomuto(Array *list, int left, int right, int pivotIndex){
    double pivotValue = list->array[pivotIndex];
    swap(&list->array[pivotIndex],&list->array[right]);
    int storeIndex = left;
    for (int i = left; i<right; i++){
        if (list->array[i] < pivotValue){
            swap(&list->array[storeIndex],&list->array[i]);
            ++storeIndex;
        }
    }
    swap(&list->array[right],&list->array[storeIndex]);
    return storeIndex;
}

double select_mio(Array *a, int left, int right, int k){
    if (left == right)        // If the list contains only one element,
        return a->array[left];  // return that element
    int pivotIndex  = left+floor(rand() % (right - left + 1));
    pivotIndex  = partition_lomuto(a, left, right, pivotIndex);
    // The pivot is in its final sorted position
    if (k == pivotIndex)
        return a->array[k];
    else if (k < pivotIndex)
        return select_mio(a, left, pivotIndex - 1, k);
    else
        return select_mio(a, pivotIndex + 1, right, k - pivotIndex);
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

int find_x_in_a(Array *a, double x){
    for (int i=0; i<a->size-1; i++){
        if (a->array[i] == x){
            return i;
        }
    }
    return -999;
}


int partition_select (Array *a, int l, int r){
    double x = select_mio(a, l , r, floor((l+r)/2));
    int index = find_x_in_a(a, x);
    return index;
}

