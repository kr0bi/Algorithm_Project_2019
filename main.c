#include <stdio.h>
#include "arrayList.h"
#include "select.h"
#include "weighted_median.h"
#include "sum.h"


int main() {
    Array *head = newArray(0.1);
    addElementToArray(head, 0.35);
    addElementToArray(head, 0.05);
    addElementToArray(head, 0.1);
    addElementToArray(head, 0.15);
    addElementToArray(head, 0.05);
    addElementToArray(head, 0.2);
    printf("Dimensione array: %d\n", head->size);
    printArray(head);
    //printf("k-esimo smallest element is %.2f", kthSmallest(head, 0, head->size-1, 3));
    printf("mediano pesato: %.2f\n", weighted_median_optimal(head, 0, head->size-1, sum_partitions(head, 0, head->size-1)));
    printf("Dimensione array: %d\n", head->size);
    printArray(head);


    /*printf("Dimensione array: %d\n", head->size);
    printArray(head);
    addElementToArray(head, 3);
    printf("Dimensione array: %d\n", head->size);
    printArray(head);

    for (int i=2; i<10; i++){
        addElementToArray(head, 100-i);
    }
    printf("Dimensione array: %d\n", head->size);
    printArray(head);

    for (int i=0; i<head->size; i++){
        head->array[i] = head->array[i] * 1.5;
    }
    printf("Dimensione array: %d\n", head->size);
    printArray(head);

    partition(head, 0, head->size-1);
    printf("Dimensione array: %d\n", head->size);
    printArray(head);*/







    return 0;
}