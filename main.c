#include <stdio.h>
#include "weighted_median.h"
#include "sum.h"
#include "sort_modifica.h"


int main() {
    double array[] = {0.1 , 0.35 , 0.05, 0.1, 0.15 , 0.05, 0.2 };
    //double array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
    int size = (int)(sizeof(array)/sizeof(array[0]));
    sort(array+10, size);
    double med_sort = weighted_median_sort(array, size);
    printf("sort: %.2f\n", med_sort);
    return 0;
}