//
// Created by lucas on 13/01/2024.
//

#ifndef JEU_ECHECS_VERIFICATION_H
#define JEU_ECHECS_VERIFICATION_H

#include "stdbool.h"
#include "affichage.h"
#include "partie.h"

#define BOARD_SIZE 8


bool verifier_piece(joueur* joueur, elem** plateau, int colonne, int ligne);
bool verifier_placement(elem** plateau, int colonne, int ligne);
bool verifier_deplacement(elem** plateau);
void verifier_promotion(joueur* joueur_actif, elem** plateau);
bool verifier_echec(joueur* active_player, joueur* inactive_player, elem** plateau, int mode);
bool verif_checkmate(elem** board, joueur* active_player, joueur* inactive_player);



#endif //JEU_ECHECS_VERIFICATION_H
