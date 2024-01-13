// Created by lucas on 12/01/2024.
//
#ifndef PLATEAU_H
#define PLATEAU_H

typedef struct element {
    char piece;
    int num_joueur;
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

#endif // PLATEAU_H
