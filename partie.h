//
// Created by lucas on 12/01/2024.
//

#ifndef JEU_ECHECS_PARTIE_H
#define JEU_ECHECS_PARTIE_H

#include "stdbool.h"

typedef struct {
    char* nom;
    char* prenom;
    int numero;
    int pion;
    int roi;
    int reine;
    int cavalier;
    int tour;
    int fou;
}joueur;

typedef struct elem {
    char piece;
    int num_joueur;
    char deplacement;
} elem;

typedef struct {
    elem ** plateau;
    joueur* joueur1;
    joueur* joueur2;
}partie;


void game(partie game, int mode);
joueur player_turn(partie partie, int tour, bool* checkmate);
void vider_buffer();
joueur bot_turn(partie game, bool* checkmate);


#endif //JEU_ECHECS_PARTIE_H
