//
// Created by daniele on 12/3/19.
//

#include "analisi_stima_dei_tempi.h"
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
    return (double)granularita/tolleranza;
}

double calcola_rip(double *array, int size, double t_min){
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
