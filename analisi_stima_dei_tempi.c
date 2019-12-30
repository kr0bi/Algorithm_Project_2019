//
// Created by daniele on 12/3/19.
//

#include "analisi_stima_dei_tempi.h"
#include <stdio.h>
#include <stdlib.h>
#include "algorithm.h"
#include <time.h>
#include <math.h>

/**
 * permette di passare piu' metodi all'interno dello stesso
 * @param handler_of_functions funzione che seleziona i metodi da passare
 * @param number_of_methods numero di metodi da passare
 * @param array
 * @param size
 * @param seed
 */
void select_method(void (**handler_of_functions)(double *, int, double *),
        int number_of_methods, double *array,
        int size, double *seed);

/**
 * calcolo della granularita dei tempi
 * @return
 */
double granularita (){
    double t0 = (double)clock();
    double t1 = (double)clock();
    while (t1 == t0){
        t1 = (double)clock();
    }
    return (t1-t0);
}
/**
 * calcolo del tempo minimo
 * @param granularita
 * @param tolleranza
 * @return
 */
double get_t_min(double granularita, double tolleranza){
    return (double)granularita/tolleranza;
}
/**
 * calcolo del numero di ripetizioni che devono essere eseguite
 * @param handler_of_functions
 * @param number_of_methods
 * @param array
 * @param size
 * @param t_min
 * @param seed
 * @return
 */
double calcola_rip(void (**handler_of_functions)(double*, int, double*),
        int number_of_methods, double *array, int size, double t_min, double *seed){

    double seed_originale = *seed;
    double t0=0.0, t1=0.0;
    int rip = 1;
    while ((t1-t0)<=t_min){
        rip *= 2;
        t0 = (double)clock();
        for (int i = 1; i<=rip; i++){
            select_method(handler_of_functions, number_of_methods, array, size, seed);
        }
        t1 = (double)clock();
    }
    //resetto il seed perche' e' stato modificato
    *seed = seed_originale;

    int max = rip;
    int min = rip/2;
    int cicli_errati = 5;
    while ((max - min)>= cicli_errati){
        rip = (max+min)/2;
        t0 = (double)clock();
        for (int i =1 ; i<=rip; i++){
            select_method(handler_of_functions, number_of_methods, array, size, seed);
        }
        t1 = (double)clock();
        if ((t1-t0)<=t_min){
            min = rip;
        }
        else {
            max = rip;
        }
    }
    *seed = seed_originale; //ripristino il seed
    return max;
}

void select_method(void (**handler_of_functions)(double*, int, double*),
        int number_of_methods, double *array,
        int size, double *seed) {
    switch (number_of_methods){
        case 1:
            (*handler_of_functions[1])(array, size, seed);
            break;
        case 2:
            (*handler_of_functions[0])(array, size, seed);
            (*handler_of_functions[1])(array, size, NULL);
            break;
        default:
            fprintf(stderr, "\nerrore: numero di metodi non supportato\n");
            break;
    }
}

/**
 * prepara l'array riempiendolo di valori generati pseudo casualmente
 * @param array
 * @param size
 * @param seed
 */
void prepara(double* array, int size, double* seed){
    for (int i=0; i<size; i++){
        array[i]=randomGenerator(seed);
    }
}

/**
 * calcolo del tempo medio netto
 * @param handler_of_methods
 * @param number_of_methods
 * @param array
 * @param size
 * @param t_min
 * @param seed
 * @return
 */
double tempo_medio_netto (void (**handler_of_methods)(double*, int, double*),
        int number_of_methods,
        double *array, int size, double t_min,
        double *seed){

    double rip_tara = calcola_rip(handler_of_methods, 1, array, size, t_min, seed);
    double rip_lordo = calcola_rip(handler_of_methods, 2, array, size, t_min, seed);
    double t0 = (double)clock();

    for (int i=1; i<=rip_tara; i++){
        (*handler_of_methods[0])(array, size, seed);
    }
    double t1 = (double)clock();
    double t_tara = (t1-t0);
    t0 = (double)clock();
    for  (int i=1; i<=rip_lordo; i++){
        (*handler_of_methods[0])(array, size, seed);
        (*handler_of_methods[1])(array, size, NULL);
    }
    t1 = (double)clock();
    double t_lordo = (t1-t0);
    double t_medio = ((t_lordo/rip_lordo) - (t_tara/rip_tara));
    return t_medio;
}

/**
 * metodo inutilizzato
 * @param handler
 * @param array
 * @param size
 * @param rip
 */
void calcolo_dei_tempi(void (*handler)(double*, int), double *array, int size, double rip){
    double t0 = (double)clock();
    for (int i = 1; i<=rip; i++){
        (*handler)(array, size);
    }
    double t1 = (double)clock();
    double t_tot = (t1-t0); //tempo totale di esecuzione
    double t_sing = t_tot/rip; //tempo medio di esecuzione
    printf("t_tot: %lf\nt_medio: %lf", t_tot, t_sing);
}

/**
 * metodo per generare numeri pseudo casuali a partire dal seed
 * @param seed
 * @return un numero pseudo casuale
 */
double randomGenerator (double *seed){
    long a = 16807;
    long m = 2147483647;
    long q = 127773;
    long r = 2836;
    double hi = trunc((*seed)/q);
    double lo = (*seed)-(q*hi);
    double test = a*lo-r*hi;
    if (test<0){
        *seed = test + m;
    } else {
        *seed = test;
    }
    return (*seed)/m;
}

/**
 * algoritmo di misurazione
 * @param handler_of_methods
 * @param number_of_methods
 * @param array
 * @param size
 * @param t_min
 * @param numero_campioni
 * @param zalpa
 * @param delta_input
 * @param seed
 */
void misurazione (void (**handler_of_methods)(double*, int, double*), int number_of_methods,
                  double *array, int size,
                  double t_min, int numero_campioni, double zalpa, double delta_input, double *seed){
    double original_seed = *seed;
    double t = 0;
    double sum_2 = 0;
    double cn = 0;
    double delta=0, e=0;
    do {
        for (int i=1; i<=numero_campioni; i++){
            double m = tempo_medio_netto(handler_of_methods, number_of_methods, array, size, t_min, seed);
            t = t + m;
            sum_2 += m*m;
        }

        *seed = original_seed;

        cn += numero_campioni;
        e = t / cn;
        double s = sqrt(sum_2/cn-(e*e));
        delta = (1/sqrt(cn))*zalpa*s;

    } while (!(delta<delta_input));
    printf("%5d\t%lf\t%lf\n", size, e, delta);
}