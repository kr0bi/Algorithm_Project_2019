//
// Created by daniele on 9/27/19.
//

#include "arrayList.h"

Array *newArray (double data){
    Array *a = malloc(sizeof(Array));
    a->array = malloc(sizeof(double));
    a->array[0] = data;
    a->size = 1;
    return a;
}

Array *newArrayLength (int length){
    Array *a = malloc(sizeof(Array));
    a->array = malloc(length*sizeof(double));
    a->size = length;
    for (int i=0; i<a->size; i++){
        a->array[i]=0.0;
    }
    return a;
}

Array *addElementToArray (Array* a, double data){
    a->array = realloc(a->array, (a->size+1)*sizeof(double));
    a->array[a->size] = data;
    a->size++;
    return a;
}


int getSize(Array *a){
    return a->size;
}
double *getArray(Array *a){
    return a->array;
}

void printArray(Array *a){
    for (int i = 0; i<a->size; i++){
        printf("%.2f ", a->array[i]);
    }
    printf("\n");
}