#include <stdio.h>
#include "weighted_median.h"
#include "algorithm.h"


int main() {
    double array[] = {0.1 , 0.35 , 0.05, 0.1, 0.15 , 0.05, 0.2 };
    int size = (int)(sizeof(array)/sizeof(array[0]));
    start_algorithm(array, size);
    return 0;
}