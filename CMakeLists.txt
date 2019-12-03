cmake_minimum_required(VERSION 3.15)
project(Algorithm_Project_2019 C)

set(CMAKE_C_STANDARD 11)

add_executable(Algorithm_Project_2019 main.c weighted_median.c weighted_median.h sum.c sum.h sort.c sort.h algorithm.c algorithm.h analisi_stima_dei_tempi.c analisi_stima_dei_tempi.h)
target_link_libraries(Algorithm_Project_2019 m)