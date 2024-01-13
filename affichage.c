// Created by lucas on 12/01/2024.
//

#include "affichage.h"

void afficher_plateau(elem** plateau) {
    printf(" ") ;
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
            if(plateau[i][j].num_joueur != '0'){
                printf("| %c%d%c ", plateau[i][j].piece, plateau[i][j].num_joueur, plateau[i][j].piece);
            }else{
                printf("|     ");
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
