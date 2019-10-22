//
// Created by daniele on 10/17/2019.
//

#include "select_miglioramento.h"
#include "sort_modifica.h"
#include <math.h>

int partition(double *ptr, int l, int r, double x){
    int i;
    for (i=l; i<r; i++)
        if (ptr[i] == x)
            break;
    swap(&ptr[i], &ptr[r]);

    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (ptr[j] <= x)
        {
            swap(&ptr[i], &ptr[j]);
            i++;
        }
    }
    swap(&ptr[i], &ptr[r]);
    return i;
}
double findMedian(double *ptr, int n){
    //TODO aggiungere indici perche' i puntatori stanno rompendo tutto
    sort(ptr, ptr+n);
    return ptr[n/2];
}
double kthSmallest(double *ptr, int l, int r, int k){
    if (k>0 &&  k<=r-l+1){
        int n = r-l+1;
        int i;
        double median[(n+4)/5]; // There will be floor((n+4)/5) groups;
        for (i=0; i<n/5; i++)
            median[i] = findMedian(ptr+l+i*5, 5);
        if (i*5 < n) {
            median[i] = findMedian(ptr+l+i*5, n%5);
            i++;
        }
        double medOfMed = (i == 1) ? median[i-1]:
                       kthSmallest(median, 0, i-1, i/2);
        int pos = partition(ptr, l, r, medOfMed);
        if (pos-l == k-1)
            return ptr[pos];
        if (pos-l > k-1) // If position is more, recur for left
            return kthSmallest(ptr, l, pos-1, k);
        return kthSmallest(ptr, pos+1, r, k-pos+l-1);
    }
    return 999;
}
void swap(double *a, double *b){
    double temp = *a;
    *a = *b;
    *b = temp;
}

int find_x_in_a(double *a, int begin, int end, double x){
    for (int i=begin; i<end; i++){
        if (a[i] == x){
            return i;
        }
    }
    return 999;
}

int partition_select (double *a, int l, int r){
    double x = kthSmallest(a, l , r, floor((r-l+1)/2));
    //double x = kthSmallest(a, l , r, floor((l+r)/2));
    //TODO CAMBIA IL FIND A PARTIRE DA L FINO AD R
    int index = find_x_in_a(a, l, r, x);
    return index;
}