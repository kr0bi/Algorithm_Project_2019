//
// Created by daniele on 12/3/19.
//

#ifndef ALGORITHM_PROJECT_2019_ANALISI_STIMA_DEI_TEMPI_H
#define ALGORITHM_PROJECT_2019_ANALISI_STIMA_DEI_TEMPI_H
//long granularita2();
//double get_t_min2 (long granularita, double tolleranza);
double granularita();
double get_t_min(double granularita, double tolleranza);
double calcola_rip_version_function(void (*start)(double*, int), double *array, int size, double t_min);
double calcola_rip(double *array, int size, double t_min);
double calcola_rip_tara(double *array, int size, double t_min);
void calcolo_dei_tempi(double *array, int size, double rip);
#endif //ALGORITHM_PROJECT_2019_ANALISI_STIMA_DEI_TEMPI_H
