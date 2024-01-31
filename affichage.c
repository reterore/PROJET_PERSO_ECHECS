// Created by lucas on 12/01/2024.
//

#include "affichage.h"
#include "stdio.h"
#include "ctype.h"
#include <stdlib.h>


void afficher_plateau(elem** plateau) {
    printf("\n ");
    for (int i = 0; i < 8; ++i) {
        printf("    %c ", 'A' + i);
    }
    // Afficher le plateau
    printf("\n");
    printf("  -");
    for (int j = 0; j < 8; ++j) {
        printf("------");
    }
    printf("\n");
    for (int i = 0; i < 8; ++i) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; ++j) {
            if(plateau[i][j].num_joueur != 0){
                printf("|%c%c%d%c%c", plateau[i][j].deplacement, plateau[i][j].piece, plateau[i][j].num_joueur, plateau[i][j].piece,  plateau[i][j].deplacement);
            }else{
                printf("|%c   %c", plateau[i][j].deplacement,plateau[i][j].deplacement);
            }
        }
        printf("|\n");
        printf("  -");
        for (int j = 0; j < 8; ++j) {
            printf("------");
        }
        printf("\n");
    }
}

void effacer_ecran() {
    printf("\e[1;1H\e[2J");
}

void afficher_pieces_joueur(joueur* j){
    printf("\npieces du joueur %s:\n", j->prenom);
    printf("pion : %d\ntour : %d\ncavalier : %d\nfou : %d\nreine: %d\n ", j->pion, j->tour, j->cavalier, j->fou, j->reine);
}


void reinitialise_check_msg(elem** board){
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if(board[i][j].deplacement == '?')
                board[i][j].deplacement = ' ';
        }
    }
}

void reset_screen(){
    for (int i = 0; i < 20; ++i) {
        printf("\n");
    }
}