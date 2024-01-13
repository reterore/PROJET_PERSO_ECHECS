// Created by lucas on 12/01/2024.
//

#include "plateau.h"

#include "affichage.h"
#include <ctype.h>

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
            if((ligne == 6 && joueur == 1 && plateau[ligne + sens][colonne].num_joueur == 0) || (ligne == 1 && joueur == 2 && plateau[ligne + sens][colonne].num_joueur == 0)){
                plateau[ligne + 2 * sens][colonne].deplacement = '-';
            }
            break;
        case '!':
            printf("vous avez choisi de jouer une tour!\n");
            for (int i = ligne + 1; i < 8; i++) {
                if (plateau[i][colonne].num_joueur == joueur) {
                    break;
                }
                plateau[i][colonne].deplacement = '-';
                if (plateau[i][colonne].num_joueur != 0) {
                    break; // Stop if opponent's piece is encountered
                }
            }
            for (int i = ligne - 1; i >= 0; i--) {
                if (plateau[i][colonne].num_joueur == joueur) {
                    break;
                }
                plateau[i][colonne].deplacement = '-';
                if (plateau[i][colonne].num_joueur != 0) {
                    break;
                }
            }

            // Check horizontal movements
            for (int j = colonne + 1; j < 8; j++) {
                if (plateau[ligne][j].num_joueur == joueur) {
                    break;
                }
                plateau[ligne][j].deplacement = '-';
                if (plateau[ligne][j].num_joueur != 0) {
                    break;
                }
            }
            for (int j = colonne - 1; j >= 0; j--) {
                if (plateau[ligne][j].num_joueur == joueur) {
                    break;
                }
                plateau[ligne][j].deplacement = '-';
                if (plateau[ligne][j].num_joueur != 0) {
                    break;
                }
            }
            break;
        case '~':
            printf("vous avez choisi de jouer un fou!\n");

            // Clear previous possible movements
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    plateau[i][j].deplacement = ' ';
                }
            }

            // Check diagonal movements (top-left to bottom-right)
            for (int i = ligne + 1, j = colonne + 1; i < 8 && j < 8; i++, j++) {
                if (plateau[i][j].num_joueur == joueur) {
                    break; // Stop if same player's piece is encountered
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break; // Stop if opponent's piece is encountered
                }
            }
            for (int i = ligne - 1, j = colonne - 1; i >= 0 && j >= 0; i--, j--) {
                if (plateau[i][j].num_joueur == joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }

            // Check diagonal movements (top-right to bottom-left)
            for (int i = ligne + 1, j = colonne - 1; i < 8 && j >= 0; i++, j--) {
                if (plateau[i][j].num_joueur == joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }
            for (int i = ligne - 1, j = colonne + 1; i >= 0 && j < 8; i--, j++) {
                if (plateau[i][j].num_joueur == joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }
            break;
        case '^':
            printf("vous avez choisis de jouer un cavalier!\n");
            int deplacement_cavalier[8][2] = {
                    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
            };
            // vérifier les deplacement possibles
            for (int i = 0; i < 8; i++) {
                int newLigne = ligne + deplacement_cavalier[i][0];
                int newColonne = colonne + deplacement_cavalier[i][1];

                // regarder si la position est dans sur le plateau
                if (newLigne >= 0 && newLigne < 8 && newColonne >= 0 && newColonne < 8 && plateau[newLigne][newColonne].num_joueur != joueur) {
                    plateau[newLigne][newColonne].deplacement = '-';
                }
            }
            break;
        case '&':
            printf("vous avez choisi de jouer une reine!\n");
            for (int i = ligne + 1; i < 8; i++) {
                if (plateau[i][colonne].num_joueur == joueur) {
                    break;
                }
                plateau[i][colonne].deplacement = '-';
                if (plateau[i][colonne].num_joueur != 0) {
                    break;
                }
            }
            for (int i = ligne - 1; i >= 0; i--) {
                if (plateau[i][colonne].num_joueur == joueur) {
                    break;
                }
                plateau[i][colonne].deplacement = '-';
                if (plateau[i][colonne].num_joueur != 0) {
                    break;
                }
            }
            for (int j = colonne + 1; j < 8; j++) {
                if (plateau[ligne][j].num_joueur == joueur) {
                    break;
                }
                plateau[ligne][j].deplacement = '-';
                if (plateau[ligne][j].num_joueur != 0) {
                    break;
                }
            }
            for (int j = colonne - 1; j >= 0; j--) {
                if (plateau[ligne][j].num_joueur == joueur) {
                    break;
                }
                plateau[ligne][j].deplacement = '-';
                if (plateau[ligne][j].num_joueur != 0) {
                    break;
                }
            }
            for (int i = ligne + 1, j = colonne + 1; i < 8 && j < 8; i++, j++) {
                if (plateau[i][j].num_joueur == joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }
            for (int i = ligne - 1, j = colonne - 1; i >= 0 && j >= 0; i--, j--) {
                if (plateau[i][j].num_joueur == joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }
            for (int i = ligne + 1, j = colonne - 1; i < 8 && j >= 0; i++, j--) {
                if (plateau[i][j].num_joueur == joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }
            for (int i = ligne - 1, j = colonne + 1; i >= 0 && j < 8; i--, j++) {
                if (plateau[i][j].num_joueur == joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }
            break;
        case '#':
            printf("vous avez choisi de jouer le roi!\n");
            int directions[8][2] = {
                    {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
                    {1, 0}, {1, -1}, {0, -1}, {-1, -1}
            };
            for (int k = 0; k < 8; k++) {
                int newLigne = ligne + directions[k][0];
                int newColonne = colonne + directions[k][1];
                if (newLigne >= 0 && newLigne < 8 && newColonne >= 0 && newColonne < 8 && plateau[newLigne][newColonne].num_joueur != joueur) {
                    plateau[newLigne][newColonne].deplacement = '-';
                }
            }
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

void promotion(int joueur, elem** plateau) {
    int reine = 0, fou = 0, cavalier = 0, tour = 0;
    char choix;
    bool test;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (plateau[i][j].num_joueur == joueur) {
                switch (plateau[i][j].piece) {
                    case '!':
                        tour++;
                        break;
                    case '~':
                        fou++;
                        break;
                    case '&':
                        reine++;
                        break;
                    case '^':
                        cavalier++;
                        break;
                }
            }
        }
    }

    if (reine < 1 || fou < 2 || cavalier < 2 || tour < 2) {
        do {
            printf("En quelle pièce voulez-vous changer votre pion?\nR: Reine - F: Fou - T: Tour - C: Cavalier\nJe choisis: ");
            scanf(" %c", &choix);
            choix = toupper(choix);

            switch (choix) {
                case 'R':
                    if (reine < 1) {
                        reine++;
                        test = true;
                    } else {
                        test = false;
                        printf("Vous avez déjà le maximum de reines possible!\n");
                    }
                    break;
                case 'F':
                    if (fou < 2) {
                        fou++;
                        test = true;
                    } else {
                        test = false;
                        printf("Vous avez déjà le maximum de fous possible!\n");
                    }
                    break;
                case 'T':
                    if (tour < 2) {
                        tour++;
                        test = true;
                    } else {
                        test = false;
                        printf("Vous avez déjà le maximum de tours possible!\n");
                    }
                    break;
                case 'C':
                    if (cavalier < 2) {
                        cavalier++;
                        test = true;
                    } else {
                        test = false;
                        printf("Vous avez déjà le maximum de cavaliers possible!\n");
                    }
                    break;
                default:
                    printf("Erreur!\n");
                    test = false;
                    break;
            }
        } while (!test);
    }
}
