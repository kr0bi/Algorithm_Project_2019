#include <stdio.h>
#include "arrayList.h"
#include "select_miglioramento.h"
#include "weighted_median.h"
#include "sum.h"
#include "sort_modifica.h"


int main() {
    double array[] = {1.5, 5.0, 4.0, 3.0, 2.0, 1.0, 10.0, 5.3};
    Array *head = newArray(1.5);
    addElementToArray(head, 5.0);
    addElementToArray(head, 4.0);
    addElementToArray(head, 3.0);
    addElementToArray(head, 2.0);
    addElementToArray(head, 1.0);
    addElementToArray(head, 10.0);
    addElementToArray(head, 5.3);
    printArray(head);

    //test sort

    /*sort(head->array, head->array+3);
    printArray(head);*/

   /* printf("k-smallest number is %d\n", partition_select(head, 0, head->size-1));
    printArray(head);*/

    double med_lin = weighted_median_optimal(head);
    double med_sort = weighted_median_sort(head);


    printf("linear: %.2f\n", med_lin);
    printf("sort: %.2f\n", med_sort);




    return 0;
}


/*//addElementToArray(head, 0.01);
    //int q = partition_select(head, 0, head->size-1);
    //printf("q: %d\n", q);

    *//*addElementToArray(head, 3.0);
    addElementToArray(head, 2.0);
    addElementToArray(head,1.0);*//*

    printf("Dimensione array: %d\n", head->size);
    printArray(head);

    //printf("il perno sta: %d\n", partition_select(head, 0, head->size-1));
    //printf("Dimensione array: %d\n", head->size);
    //printArray(head);

    *//*Array *ciccio = newArray(1);
    addElementToArray(ciccio, 2);
    addElementToArray(ciccio, 3);
    addElementToArray(ciccio, 4);
    addElementToArray(ciccio, 5);
    addElementToArray(ciccio,6);
    addElementToArray(ciccio, 7);
    printf("Dimensione array: %d\n", ciccio->size);
    printArray(ciccio);*//*


    double med_lin = weighted_median_optimal(head);
    double med_sort = weighted_median_sort(head);


    printf("linear: %.2f\n", med_lin);
    printf("sort: %.2f\n", med_sort);

    *//*if (med_sort == med_lin){
        printf("true\n");
    } else {
        printf("false\n");
    }*//*


    *//*printf("Dimensione array: %d\n", head->size);
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