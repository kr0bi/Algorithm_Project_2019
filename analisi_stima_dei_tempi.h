//
// Created by daniele on 12/3/19.
//

#ifndef ALGORITHM_PROJECT_2019_ANALISI_STIMA_DEI_TEMPI_H
#define ALGORITHM_PROJECT_2019_ANALISI_STIMA_DEI_TEMPI_H
#include <stdlib.h>
#include <bits/types/FILE.h>

//long granularita2();
//double get_t_min2 (long granularita, double tolleranza);
double granularita();
double get_t_min(double granularita, double tolleranza);

double calcola_rip(void (**handler_of_methods)(double*, long, double*), int number_of_methods, double *array, long size, double t_min);
void prepara (double* array, long size, double* array_to_copy);
double tempo_medio_netto (void (**handler_of_methods)(double*, long, double*), int number_of_methods,
        double *array, long size, double *array_to_copy, double t_min);
void calcolo_dei_tempi(void (*handler)(double*, int), double *array, long size, double rip);

double randomGenerator (double *seed);

void popola_array(double *array, long size, double *seed);

void misurazione (void (**handler_of_methods)(double*, long, double*), int number_of_methods,
        double *array, long size, double *array_to_copy, double t_min, int numero_campioni, int zalpa, double delta_input, double *seed,
        FILE *file);
#endif //ALGORITHM_PROJECT_2019_ANALISI_STIMA_DEI_TEMPI_H
