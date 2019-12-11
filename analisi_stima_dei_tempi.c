//
// Created by daniele on 12/3/19.
//

#include "analisi_stima_dei_tempi.h"
#include <stdio.h>
#include "algorithm.h"
#include <time.h>

double granularita (){
    clock_t t0 = clock();
    clock_t t1 = clock();
    while (t1 == t0){
        t1 = clock();
    }
    return (double)(t1-t0)/CLOCKS_PER_SEC;
}
double get_t_min(double granularita, double tolleranza){
    return (double)(granularita/tolleranza);
}
double calcola_rip(void (**handler_of_functions)(double*, int), int number_of_methods, double *array, int size, double t_min){
    clock_t t0, t1;
    int rip = 1;
    while ((double)(t1-t0)<=t_min){
        rip *= 2;
        t0 = clock();
        for (int i = 1; i<rip; i++){
            for (int j=0; j<number_of_methods; j++) {
                (*handler_of_functions[j])(array, size);
            }
        }
        t1 = clock();
    }
    int max = rip;
    int min = rip/2; //prova se viene approssimato
    int cicli_errati = 5;
    while ((max - min)>= cicli_errati){
        rip = (max+min)/2;
        t0 = clock();
        for (int i =1 ; i<rip; i++){
            for (int j=0; i<number_of_methods; j++) {
                (*handler_of_functions[j])(array, size);
            }
        }
        t1 = clock();
        if ((double)(t1-t0)<=t_min){
            min = rip;
        }
        else {
            max = rip;
        }
    }
    return max;
}

void prepara(double* array, int size){

}
/*double calcola_rip(double *array, int size, double t_min){
    clock_t t0, t1;
    int rip = 1;
    while ((double)(t1-t0)<=t_min){
        rip *= 2;
        t0 = clock();
        for (int i = 1; i<rip; i++){
            start_algorithm(array, size);
        }
        t1 = clock();
    }
    int max = rip;
    int min = rip/2; //prova se viene approssimato
    int cicli_errati = 5;
    while ((max - min)>= cicli_errati){
        rip = (max+min)/2;
        t0 = clock();
        for (int i =1 ; i<rip; i++){
            start_algorithm(array, size);
        }
        t1 = clock();
        if ((double)(t1-t0)<=t_min){
            min = rip;
        }
        else {
            max = rip;
        }
    }
    return max;
}*/

double calcola_rip_tara(double *array, int size, double t_min){
    clock_t t0, t1;
    int rip = 1;
    while ((double)(t1-t0)<=t_min){
        rip *= 2;
        t0 = clock();
        for (int i = 1; i<rip; i++){
            start_algorithm(array, size);
        }
        t1 = clock();
    }
    int max = rip;
    int min = rip/2; //prova se viene approssimato
    int cicli_errati = 5;
    while ((max - min)>= cicli_errati){
        rip = (max+min)/2;
        t0 = clock();
        for (int i =1 ; i<rip; i++){
            start_algorithm(array, size);
        }
        t1 = clock();
        if ((double)(t1-t0)<=t_min){
            min = rip;
        }
        else {
            max = rip;
        }
    }
    return max;
}

void calcolo_dei_tempi(double *array, int size, double rip){
    clock_t t0 = clock();
    for (int i = 1; i<rip; i++){
        start_algorithm(array, size);
    }
    clock_t t1 = clock();
    double t_tot = (double)t1-t0; //tempo totale di esecuzione
    double t_sing = t_tot/rip; //tempo medio di esecuzione
    printf("t_tot: %lf\nt_medio: %lf", t_tot, t_sing);
}


/*long granularita2 (){
    struct timespec t0;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    struct timespec t1;
    clock_gettime(CLOCK_MONOTONIC, &t1);
    while (t1.tv_nsec == t0.tv_nsec && t1.tv_sec == t0.tv_sec){
        clock_gettime(CLOCK_MONOTONIC, &t1);
    }
    long res = (t1.tv_sec-t0.tv_sec)*1000000000+(t1.tv_nsec-t0.tv_nsec);
    return res;
}

double get_t_min2 (long granularita, double tolleranza){
    return (double)(granularita/tolleranza);
}*/