// Created by lucas on 12/01/2024.
//

#include "plateau.h"

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
