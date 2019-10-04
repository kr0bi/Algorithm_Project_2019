//
// Created by daniele on 9/27/19.
//

#include "arrayList.h"
#include <math.h>

#ifndef ALGORITHM_PROJECT_2019_SELECT_H
#define ALGORITHM_PROJECT_2019_SELECT_H
/*
 * Standard partition di QuickSort()
 * Considera l'ultimo elemento come pivot
 * e muove tutti gli elementi minori a sinistra di esso
 * e quelli maggiori a destra
 */
int partition (Array* a, int l, int r);

/*
 * Questa funzione torna il k-esimo elemento piu' piccolo
 * nell'array in posizione [l...r] usando un metodo basato su QuickSort
 * ASSUNZIONE: Tutti gli elementi in a[] sono distinti
 */

double kthSmallest(Array* a, int l, int r, int k);

/*
 * Funzione di swap di due elementi
 */
void swap (double* a, double *b);

int partition_select (Array *a, int l, int r);

#endif //ALGORITHM_PROJECT_2019_SELECT_H
