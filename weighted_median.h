//
// Created by daniele on 9/27/19.
//

#ifndef ALGORITHM_PROJECT_2019_WEIGHTED_MEDIAN_H
#define ALGORITHM_PROJECT_2019_WEIGHTED_MEDIAN_H

#include "arrayList.h"

double weighted_median_sort(Array *ptr);
double weighted_median_optimal(Array *ptr);
double weighted_median_optimal_rec(Array *ptr, int p, int r, double w);

#endif //ALGORITHM_PROJECT_2019_WEIGHTED_MEDIAN_H
