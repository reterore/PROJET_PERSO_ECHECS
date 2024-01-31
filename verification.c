//
// Created by lucas on 13/01/2024.
//

#include "verification.h"
#include "plateau.h"


bool verifier_piece(joueur* joueur, elem** plateau, int colonne, int ligne) {
    // Vérifier que les indices de ligne et de colonne sont valides
    if (colonne < 0 || colonne >= BOARD_SIZE || ligne < 0 || ligne >= BOARD_SIZE) {
        printf("Erreur : Indices de ligne (%d) ou de colonne (%d) invalides!\n\n", colonne, ligne);
        return false;
    }

    // Vérifier que la case n'est pas vide
    if (plateau[ligne][colonne].piece == ' ') {
        reset_screen();
        printf("Erreur : La case est vide!\n\n");
        return false;
    }

    // Vérifier le joueur de la pièce à la position spécifiée
    if (plateau[ligne][colonne].num_joueur != joueur->numero) {
        reset_screen();
        printf("Erreur : Vous ne pouvez pas jouer cette piece!\n\n");
        return false;
    }

    return true;
}

bool verifier_placement(elem** plateau, int colonne, int ligne) {
    // Vérifier que les indices de ligne et de colonne sont valides
    if (colonne < 0 || colonne >= BOARD_SIZE || ligne < 0 || ligne >= BOARD_SIZE) {
        printf("Indices de ligne (%d) ou de colonne (%d) invalides!\n\n", colonne, ligne);
        return false;
    }

    // Vérifier le joueur de la pièce à la position spécifiée
    if (plateau[ligne][colonne].deplacement == '-') {
        return true;
    } else {
        reset_screen();
        printf("Vous ne pouvez pas poser une piece ici!\n\n");
        return false;
    }
}

bool verifier_deplacement(elem** plateau){
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if(plateau[i][j].deplacement == '-'){
                return true;
            }
        }
    }
    reset_screen();
    printf("/!\\ Aucun deplacement possible pour cette piece /!\\\n");
    return false;
}

void verifier_promotion(joueur* joueur_actif, elem** plateau) {
    int limit = (joueur_actif->numero == 1) ? 0 : 7;
    for (int i = 0; i < 8; ++i) {
        if (plateau[limit][i].piece == '*' && plateau[limit][i].num_joueur == joueur_actif->numero) {
            promotion(joueur_actif, plateau, limit, i);
        }
    }
}

bool verifier_echec(joueur* active_player, joueur* inactive_player, elem** plateau, int mode){
    // Vérifier l'échec précoce ici si une pièce du joueur actif peut capturer le roi adverse.

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (plateau[i][j].num_joueur != active_player->numero) {
                definir_deplacement(inactive_player, plateau, j, i);
            }
        }
    }
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (plateau[i][j].num_joueur == active_player->numero && plateau[i][j].piece == '#' && plateau[i][j].deplacement == '-') {
                if(mode == 1){
                    printf("/!\\ Vous etes en echec /!\\ \n");
                }
                plateau[i][j].deplacement = '?';
                return true;
            }
        }
    }
    return false;
}

bool verif_checkmate(elem** board, joueur* active_player, joueur* inactive_player) {
        // Examinez tous les mouvements possibles pour chaque pièce
    reinitialiser_deplacement(board);
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j].num_joueur == active_player->numero) {
                char piece = board[i][j].piece;
                definir_deplacement(active_player, board, i, j);
                // Parcourez tous les mouvements possibles
                for (int k = 0; k < BOARD_SIZE; ++k) {
                    for (int l = 0; l < BOARD_SIZE; ++l) {
                        if (board[k][l].deplacement == '-') {
                            // Simulation du mouvement
                            elem** test_board = dupliquer_plateau(board);
                            placer_piece(active_player, test_board, k, l, piece);
                            // Vérifier si le roi est toujours en échec après le mouvement
                            if (!verifier_echec(active_player, inactive_player, test_board, 0)) {
                                liberer_plateau(test_board);
                                return false;  // Échec et mat n'est pas confirmé
                            }

                            liberer_plateau(test_board);
                        }
                    }
                }

                // Réinitialiser le plateau après la simulation
                reinitialiser_deplacement(board);
            }
        }
    }
    // Aucun mouvement possible n'a résolu l'échec, c'est donc un échec et mat
    return true;
}