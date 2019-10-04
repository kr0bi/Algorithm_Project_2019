//
// Created by daniele on 9/27/19.
//

#include "arrayList.h"

#ifndef ALGORITHM_PROJECT_2019_SORT_H
#define ALGORITHM_PROJECT_2019_SORT_H

//implementazione di un algoritmo di sorting: mergesort
void sort (Array *ptr);
void mergesort(Array *ptr, int p, int q);
void merge(Array *ptr, int p, int q, int r);

#endif //ALGORITHM_PROJECT_2019_SORT_H
