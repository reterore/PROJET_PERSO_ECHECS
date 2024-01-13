//
// Created by lucas on 13/01/2024.
//

#ifndef JEU_ECHECS_VERIFICATION_H
#define JEU_ECHECS_VERIFICATION_H

#include "plateau.h"
#include "affichage.h"


bool verifier_piece(int joueur, elem** plateau, int colonne, int ligne);
bool verifier_placement(elem** plateau, int colonne, int ligne);
bool verifier_deplacement(elem** plateau);
void verifier_promotion(int joueur, elem** plateau);


#endif //JEU_ECHECS_VERIFICATION_H
