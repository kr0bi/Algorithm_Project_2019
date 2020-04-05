clang -c sum.h sum.c
clang -c sort.h sort.c
clang -c weighted_median.h weighted_median.c sum.h sort.h
clang -c algorithm.h algorithm.c weighted_median.h
clang -c analisi_stima_dei_tempi.h analisi_stima_dei_tempi.c algorithm.h
clang -c main.c weighted_median.h algorithm.h analisi_stima_dei_tempi.h
clang -o main.out main.o algorithm.o analisi_stima_dei_tempi.o sort.o sum.o weighted_median.o -lm
