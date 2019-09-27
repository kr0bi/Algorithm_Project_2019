//
// Created by daniele on 9/27/19.
//

#ifndef ALGORITHM_PROJECT_2019_ARRAYLIST_H
#define ALGORITHM_PROJECT_2019_ARRAYLIST_H
#include <stdio.h>
#include <stdlib.h>
struct arrayList{
    double* array;
    int size;
};

typedef struct arrayList Array;

Array *newArray (double data);
Array *addElementToArray (Array *a, double data);

int getSize(Array *a);
double *getArray(Array *a);

void printArray(Array *a);
#endif //ALGORITHM_PROJECT_2019_ARRAYLIST_H
