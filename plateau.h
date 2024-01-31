// Created by lucas on 12/01/2024.
//
#ifndef PLATEAU_H
#define PLATEAU_H

#include <stdio.h>
#include <stdbool.h>
#include "partie.h"
#include "verification.h"

void initialiser_plateau(elem** plateau);
elem** dupliquer_plateau(elem** original);
void liberer_plateau(elem** plateau);
void reinitialiser_deplacement(elem** plateau);
void definir_deplacement(joueur* joueur, elem** plateau, int colonne, int ligne);
void enlever_piece(elem** plateau, int colonne, int ligne);
void retirer_piece_joueur(elem** plateau, int colonne, int ligne, joueur* j);
void placer_piece(joueur* joueur, elem** plateau, int colonne, int ligne, char piece);
void promotion(joueur* joueur, elem** plateau, int row, int column);


#endif // PLATEAU_H
