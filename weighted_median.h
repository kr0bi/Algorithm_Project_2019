//
// Created by daniele on 9/27/19.
//
#include <math.h>

#ifndef ALGORITHM_PROJECT_2019_WEIGHTED_MEDIAN_H
#define ALGORITHM_PROJECT_2019_WEIGHTED_MEDIAN_H

double weighted_median_sort(double *ptr, int size);
double weighted_median_optimal(double *ptr, int size);
double weighted_median_optimal_rec(double *ptr, int p, int r, double w, double w2);

#endif //ALGORITHM_PROJECT_2019_WEIGHTED_MEDIAN_H
