//
// Created by daniele on 9/27/19.
//
#include "sum.h"
/**
 * somma i valori tra l'indice p e q compresi
 * @param ptr array da passare
 * @param p indice iniziale
 * @param q indice finale
 * @return
 */
double sum_partitions(double *ptr, int p, int q){
    double sum = 0.0;
    for (int i = p; i<=q; i++){
        sum += ptr[i];
    }
    return sum;
}
