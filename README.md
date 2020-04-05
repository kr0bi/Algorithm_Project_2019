# Algorithm_Project_2019

# Introduzione
Facendo riferimento alla relazione: il problema è di calcolare la mediana (inferiore) pesata di una generica sequenza di valori razionali positivi.

La mediana pesata inferiore è il numero che, sommato ai suoi elementi precedenti (ordinati), supera o è uguale alla loro somma W diviso due.

# Specifiche per il formato dell'input e dell'output
L'input del programma consiste in una sequenza di numeri razionali separati da una virgola (ignorando gli spazi) e terminante con un punto. Tutti i numeri compresi i numeri interi come 1 verrano inseririti in input come 1.0.

L'input è fornito da stdin e l'output è stampato in stdout.

# Come compilare il progetto
# Prerequisiti
* clang (o gcc)
# Compilazione
``` bash
clang -c sum.h sum.c
clang -c sort.h sort.c
clang -c weighted_median.h weighted_median.c sum.h sort.h
clang -c algorithm.h algorithm.c weighted_median.h
clang -c analisi_stima_dei_tempi.h analisi_stima_dei_tempi.c algorithm.h
clang -c main.c weighted_median.h algorithm.h analisi_stima_dei_tempi.h
clang -o main-out main.o algorithm.o analisi_stima_dei_tempi.o sort.o sum.o weighted_median.o -lm
```

Altrimenti viene fornito un piccolo script in bash per eseguire questi comandi.

Per eseguirlo è necessario:
``` bash
chmod 755 compile.sh
./compile.sh
```
