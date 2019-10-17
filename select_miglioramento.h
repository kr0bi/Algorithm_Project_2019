//
// Created by daniele on 10/17/2019.
//

#include "arrayList.h"

#ifndef ALGORITHM_PROJECT_2019_SELECT_MIGLIORAMENTO_H
#define ALGORITHM_PROJECT_2019_SELECT_MIGLIORAMENTO_H

int partition(Array *ptr, int l, int r, double x);
double findMedian(double *ptr, int n);
double kthSmallest(Array *ptr, int l, int r, int k);
void swap(double *a, double *b);
int partition_select (Array *a, int l, int r);

#endif //ALGORITHM_PROJECT_2019_SELECT_MIGLIORAMENTO_H
