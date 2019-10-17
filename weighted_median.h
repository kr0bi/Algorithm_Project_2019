//
// Created by daniele on 9/27/19.
//
#include "arrayList.h"
#include <math.h>

#ifndef ALGORITHM_PROJECT_2019_WEIGHTED_MEDIAN_H
#define ALGORITHM_PROJECT_2019_WEIGHTED_MEDIAN_H

double weighted_median_sort(Array *ptr);
double weighted_median_optimal(Array *ptr);
double weighted_median_optimal_rec(Array *ptr, int p, int r, double w, double w2);

#endif //ALGORITHM_PROJECT_2019_WEIGHTED_MEDIAN_H
