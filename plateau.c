// Created by lucas on 12/01/2024.
//

#include "plateau.h"
#include "affichage.h"

void initialiser_plateau(elem** plateau) {
    // Initialiser la base du plateau
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            plateau[i][j].piece = '_'; // Utilisation du caractère '#'
            plateau[i][j].num_joueur = 0;  // Initialisation avec le caractère '0'
        }
    }
    for (int i = 0; i < 8; ++i) {
        plateau[0][i].num_joueur = 2;
        plateau[1][i].num_joueur = 2;
        plateau[6][i].num_joueur = 1;
        plateau[7][i].num_joueur = 1;
        plateau[6][i].piece = '*';
        plateau[1][i].piece = '*';


    }
    //ligne du joueur 2
    plateau[0][0].piece = '!'; // Utilisation du caractère '!'
    plateau[0][1].piece = '^'; // Utilisation du caractère '~'
    plateau[0][2].piece = '~'; // Utilisation du caractère '+'
    plateau[0][3].piece = '&'; // Utilisation du caractère '&'
    plateau[0][4].piece = '#'; // Utilisation du caractère '!'
    plateau[0][5].piece = '^'; // Utilisation du caractère '~'
    plateau[0][6].piece = '~'; // Utilisation du caractère '+'
    plateau[0][7].piece = '!'; // Utilisation du caractère '&'
    //ligne du joueur 1
    plateau[7][0].piece = '!'; // Utilisation du caractère 't'
    plateau[7][1].piece = '^'; // Utilisation du caractère '!'
    plateau[7][2].piece = '~'; // Utilisation du caractère '+'
    plateau[7][3].piece = '#'; // Utilisation du caractère '#'
    plateau[7][4].piece = '&'; // Utilisation du caractère 't'
    plateau[7][5].piece = '~'; // Utilisation du caractère '!'
    plateau[7][6].piece = '^'; // Utilisation du caractère '+'
    plateau[7][7].piece = '!'; // Utilisation du caractère '#'

}

void reinitialiser_deplacement(elem** plateau){
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            plateau[i][j].deplacement = ' ';
        }
    }
}

void definir_deplacement(int joueur, elem** plateau, int colonne, int ligne){
    char piece = plateau[ligne][colonne].piece;
    int sens = (joueur == 1) ? -1 : 1;
    switch (piece) {
        case '*':
            printf("vous avez choisis de jouer un pion!\n");
            if(plateau[ligne + sens][colonne + sens].num_joueur != joueur && plateau[ligne + sens][colonne + sens].num_joueur != 0
                    ){
                plateau[ligne + sens][colonne + sens].deplacement = '-';
            }
            if(plateau[ligne - sens][colonne + sens].num_joueur != joueur && plateau[ligne - sens][colonne + sens].num_joueur != 0
                    ){
                plateau[ligne - sens][colonne + sens].deplacement = '-';
            }
            if(plateau[ligne + sens][colonne].num_joueur == 0){
                plateau[ligne + sens][colonne].deplacement = '-';
            }
            if((ligne == 6 && joueur == 1) || (ligne == 1 && joueur == 2)){
                plateau[ligne + 2 * sens][colonne].deplacement = '-';
            }
            break;
        case '!':
            printf("vous avez choisis de jouer une tour!\n");
            break;
        default:
            printf("piece inconnue!\n");
    }
}

void enlever_piece(elem** plateau, int colonne, int ligne){
    plateau[ligne][colonne].piece = ' ';
    plateau[ligne][colonne].deplacement = ' ';
    plateau[ligne][colonne].num_joueur = 0;
}

void placer_piece(int joueur, elem** plateau, int colonne, int ligne, char piece) {
    plateau[ligne][colonne].piece = piece;
    plateau[ligne][colonne].num_joueur = joueur;
}
