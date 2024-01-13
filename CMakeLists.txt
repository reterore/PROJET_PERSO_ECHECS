cmake_minimum_required(VERSION 3.24)
project(Jeu_Echecs C)

set(CMAKE_C_STANDARD 99)

add_executable(Jeu_Echecs main.c plateau.c affichage.h affichage.c partie.h partie.c verification.c)
