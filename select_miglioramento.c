//
// Created by daniele on 10/17/2019.
//

#include "select_miglioramento.h"
#include "sort_modifica.h"
#include <math.h>

int partition(Array *ptr, int l, int r, double x){
    // Search for x in arr[l..r] and move it to end
    int i;
    for (i=l; i<r; i++)
        if (ptr->array[i] == x)
            break;
    swap(&ptr->array[i], &ptr->array[r]);

    // Standard partition algorithm
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (ptr->array[j] <= x)
        {
            swap(&ptr->array[i], &ptr->array[j]);
            i++;
        }
    }
    swap(&ptr->array[i], &ptr->array[r]);
    return i;
}
double findMedian(double *ptr, int n){
    sort(ptr, ptr+n);
    return ptr[n/2];
}
double kthSmallest(Array *ptr, int l, int r, int k){
    if (k>0 && k<=r-l+1){
        int n = r-l;
        int i;
        Array *median = newArrayLength((n+4)/5);
        //double median[(n+4)/5]; // There will be floor((n+4)/5) groups;
        for (i=0; i<n/5; i++)
            median->array[i] = findMedian(ptr->array+l+i*5, 5);
        if (i*5 < n) {
            median->array[i] = findMedian(ptr->array+l+i*5, n%5);
            i++;
        }
        double medOfMed = (i == 1) ? median->array[i-1]:
                       kthSmallest(median, 0, i-1, i/2);
        int pos = partition(ptr, l, r, medOfMed);
        if (pos-l == k-1)
            return ptr->array[pos];
        if (pos-l > k-1) // If position is more, recur for left
            return kthSmallest(ptr, l, pos-1, k);
        return kthSmallest(ptr, pos+1, r, k-pos+l-1);
    }
    return k;
}
void swap(double *a, double *b){
    double temp = *a;
    *a = *b;
    *b = temp;
}

int find_x_in_a(Array *a, double x){
    for (int i=0; i<a->size-1; i++){
        if (a->array[i] == x){
            return i;
        }
    }
    return x;
}

int partition_select (Array *a, int l, int r){
    double x = kthSmallest(a, l , r, floor((l+r)/2));
    int index = find_x_in_a(a, x);
    return index;
}