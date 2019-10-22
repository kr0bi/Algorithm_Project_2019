#include <stdio.h>
#include "select_miglioramento.h"
#include "weighted_median.h"
#include "sum.h"
#include "sort_modifica.h"


int main() {
    double array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
    int size = (int)(sizeof(array)/sizeof(array[0]));
    sort(array+10, array+19);
    //double x = kthSmallest(array, 0 , size-1, floor((size-0)/2));
    //printf("%lf\n", x);

    //findMedian(array, 3);
    //partition(array, 0, size-1, 3.0);
    //double med_lin = weighted_median_optimal(array, size);
    double med_sort = weighted_median_sort(array, size);

    //printf("linear: %.2f\n", med_lin);
    printf("sort: %.2f\n", med_sort);

    return 0;
}