//
// Created by lucas on 13/01/2024.
//

#include "verification.h"


bool verifier_piece(int joueur, elem** plateau, int colonne, int ligne) {
    // Vérifier que les indices de ligne et de colonne sont valides
    if (colonne < 0 || colonne >= 8 || ligne < 0 || ligne >= 8) {
        printf("Indices de ligne ou de colonne invalides!\n\n");
        return false;
    }

    // Vérifier le joueur de la pièce à la position spécifiée
    afficher_plateau(plateau);
    if (plateau[ligne][colonne].num_joueur != joueur) {
        printf("Vous ne pouvez pas jouer cette piece!\n\n");
        return false;
    }
    return true;
}

bool verifier_placement(int joueur, elem** plateau, int colonne, int ligne) {
    // Vérifier que les indices de ligne et de colonne sont valides
    if (colonne < 0 || colonne >= 8 || ligne < 0 || ligne >= 8) {
        printf("Indices de ligne ou de colonne invalides!\n\n");
        printf("%d , %d\n\n", colonne, ligne);
        return false;
    }

    // Vérifier le joueur de la pièce à la position spécifiée
    afficher_plateau(plateau);
    if (plateau[ligne][colonne].deplacement == '-') {
        printf("Vous pouvez poser cette piece ici\n\n");
        return true;
    } else {
        printf("Vous ne pouvez pas poser cette piece ici!\n\n");
        return false;
    }
}
