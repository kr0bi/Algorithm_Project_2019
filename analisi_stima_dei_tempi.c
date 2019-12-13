//
// Created by daniele on 12/3/19.
//

#include "analisi_stima_dei_tempi.h"
#include <stdio.h>
#include "algorithm.h"
#include <time.h>
#include <math.h>

void select_method(void (**handler_of_functions)(double *, int, double *), int number_of_methods, const double *array,
                   int size);

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
double calcola_rip(void (**handler_of_functions)(double*, int, double*), int number_of_methods, double *array, int size, double t_min){
    clock_t t0, t1;
    int rip = 1;
    while ((double)(t1-t0)<=t_min){
        rip *= 2;
        t0 = clock();
        for (int i = 1; i<rip; i++){
            select_method(handler_of_functions, number_of_methods, array, size);
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
            select_method(handler_of_functions, number_of_methods, array, size);
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

void select_method(void (**handler_of_functions)(double *, int, double *), int number_of_methods, const double *array,
                   int size) {
    switch (number_of_methods){
        case 1:
            (*handler_of_functions[1])(array, size, NULL);
            break;
        case 2:
            (*handler_of_functions[0])(array, size, array);
            (*handler_of_functions[1])(array, size, NULL);
            break;
        default:
            fprintf(stderr, "\nerrore: numero di metodi non supportato\n");
            break;
    }
}

void prepara(double* array, int size, double* array_to_copy){
    for (int i=0; i<size; i++){
        array[i]=array_to_copy[i];
    }
}

double tempo_medio_netto (void (**handler_of_methods)(double*, int, double*), int number_of_methods, double *array, int size, double* array_to_copy, double t_min){
    double rip_tara = calcola_rip(handler_of_methods, 1, array, size, t_min);
    double rip_lordo = calcola_rip(handler_of_methods, 2, array, size, t_min);
    clock_t t0 = clock();
    for (int i=1; i<rip_tara; i++){
        (*handler_of_methods[0])(array, size, array_to_copy);
    }
    clock_t t1 = clock();
    clock_t t_tara = (t1-t0);
    t0 = clock();
    for  (int i=1; i<rip_lordo; i++){
        (*handler_of_methods[0])(array, size, array_to_copy);
        (*handler_of_methods[1])(array, size, array_to_copy);
    }
    t1 = clock();
    clock_t t_lordo = clock();
    //double t_medio = (((double)t_lordo/rip_lordo) - ((double)t_tara/rip_tara))/CLOCKS_PER_SEC;
    double t_medio = (((double)t_lordo/CLOCKS_PER_SEC/rip_lordo) - ((double)t_tara/CLOCKS_PER_SEC/rip_tara));
    //printf("tempo medio: %lf", t_medio);
    return t_medio;
}

void calcolo_dei_tempi(void (*handler)(double*, int), double *array, int size, double rip){
    clock_t t0 = clock();
    for (int i = 1; i<rip; i++){
        (*handler)(array, size);
    }
    clock_t t1 = clock();
    double t_tot = (double)t1-t0; //tempo totale di esecuzione
    double t_sing = t_tot/rip; //tempo medio di esecuzione
    printf("t_tot: %lf\nt_medio: %lf", t_tot, t_sing);
}

double randomGenerator (double *seed){
    long a = 16807;
    long m = 2147483647;
    long q = 127773;
    long r = 2836;
    double hi = trunc((*seed)/q);
    double lo = (*seed)-q*hi;
    double test = a*lo-r*hi;
    if (test<0){
        *seed = test + m;
    } else {
        *seed = test;
    }
    return (*seed)/m;
}

void popola_array(double *array, int size, double *seed){
    for (int i=0; i<size; i++){
        array[i] = randomGenerator(seed);
    }
}

void misurazione (void (**handler_of_methods)(double*, int, double*), int number_of_methods,
                  double *array, int size, double *array_to_copy, double t_min, int numero_campioni, int zalpa, double delta_input, double *seed){
    double t = 0;
    double sum_2 = 0;
    double cn = 0;
    double delta, e;
    do {
        for (int i=1; i<numero_campioni; i++){
            double m = tempo_medio_netto(handler_of_methods, number_of_methods, array, size, array_to_copy, t_min);
            t = t + m;
            sum_2 += m*m;
        }
        cn += numero_campioni;
        e = t / cn;
        double s = sqrt(sum_2/cn-(e*e));
        delta = (1/sqrt(cn))*zalpa*s;
    } while (!(delta<delta_input));
    printf("e: %lf - delta: %lf", e, delta);
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