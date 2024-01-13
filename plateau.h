// Created by lucas on 12/01/2024.
//
#ifndef PLATEAU_H
#define PLATEAU_H

#include <stdio.h>
#include <stdbool.h>



typedef struct elem {
    char piece;
    int num_joueur;
    char deplacement;
} elem;

enum Colonne {
    A = 1,
    B,
    C,
    D,
    E,
    F,
    G,
    H
};

void initialiser_plateau(elem** plateau);
void reinitialiser_deplacement(elem** plateau);
void definir_deplacement(int joueur, elem** plateau, int colonne, int ligne);
void enlever_piece(elem** plateau, int colonne, int ligne);
void placer_piece(int joueur, elem** plateau, int colonne, int ligne, char piece);
void promotion(int joueur, elem** plateau);


#endif // PLATEAU_H
