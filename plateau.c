// Created by lucas on 12/01/2024.
//

#include "plateau.h"
#include "affichage.h"
#include <ctype.h>
#include "malloc.h"

void initialiser_plateau(elem** plateau) {
    // Initialiser la base du plateau
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            plateau[i][j].piece = '_';
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
    plateau[0][0].piece = '!';
    plateau[0][1].piece = '^';
    plateau[0][2].piece = '~';
    plateau[0][3].piece = '&';
    plateau[0][4].piece = '#';
    plateau[0][5].piece = '~';
    plateau[0][6].piece = '^';
    plateau[0][7].piece = '!';
    //ligne du joueur 1
    plateau[7][0].piece = '!';
    plateau[7][1].piece = '^';
    plateau[7][2].piece = '~';
    plateau[7][3].piece = '&';
    plateau[7][4].piece = '#';
    plateau[7][5].piece = '~';
    plateau[7][6].piece = '^';
    plateau[7][7].piece = '!';

}

elem** dupliquer_plateau(elem** original) {
    elem** copie = (elem**)malloc(8 * sizeof(elem*));
    for (int i = 0; i < 8; ++i) {
        copie[i] = (elem*)malloc(8 * sizeof(elem));
        for (int j = 0; j < 8; ++j) {
            copie[i][j] = original[i][j];
        }
    }
    return copie;
}

void liberer_plateau(elem** plateau) {
    for (int i = 0; i < 8; ++i) {
        free(plateau[i]);
    }
    free(plateau);
}

void reinitialiser_deplacement(elem** plateau){
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if(plateau[i][j].deplacement != '?')
            plateau[i][j].deplacement = ' ';
        }
    }
}

void definir_deplacement(joueur* joueur, elem** plateau, int colonne, int ligne){
    char piece = plateau[ligne][colonne].piece;
    int num_joueur = joueur->numero;
    int sens = (num_joueur == 1) ? -1 : 1;
    int directions[8][2] = {
            {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
            {1, 0}, {1, -1}, {0, -1}, {-1, -1}
    };
    int deplacement_cavalier[8][2] = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    switch (piece) {
        case '*':
            if (ligne + sens >= 0 && ligne + sens < 8) {
                // Déplacement simple
                if (plateau[ligne + sens][colonne].num_joueur == 0) {
                    plateau[ligne + sens][colonne].deplacement = '-';
                }

                // Déplacement double depuis la ligne de départ
                if ((ligne == 6 && num_joueur == 1 || ligne == 1 && num_joueur == 2) && plateau[ligne + 2 * sens][colonne].num_joueur == 0) {
                    plateau[ligne + 2 * sens][colonne].deplacement = '-';
                }
            }

            // Capture en diagonale
            if (ligne + sens >= 0 && ligne + sens < 8 && colonne + sens >= 0 && colonne + sens < 8) {
                if (plateau[ligne + sens][colonne + sens].num_joueur != num_joueur && plateau[ligne + sens][colonne + sens].num_joueur != 0) {
                    plateau[ligne + sens][colonne + sens].deplacement = '-';
                }
            }

            if (ligne + sens >= 0 && ligne + sens < 8 && colonne - sens >= 0 && colonne - sens < 8) {
                if (plateau[ligne + sens][colonne - sens].num_joueur != num_joueur && plateau[ligne + sens][colonne - sens].num_joueur != 0) {
                    plateau[ligne + sens][colonne - sens].deplacement = '-';
                }
            }
            break;
        case '!':
            for (int i = ligne + 1; i < 8; i++) {
                if (plateau[i][colonne].num_joueur == num_joueur) {
                    break;
                }
                plateau[i][colonne].deplacement = '-';
                if (plateau[i][colonne].num_joueur != 0) {
                    break; // Stop if opponent's piece is encountered
                }
            }
            for (int i = ligne - 1; i >= 0; i--) {
                if (plateau[i][colonne].num_joueur == num_joueur) {
                    break;
                }
                plateau[i][colonne].deplacement = '-';
                if (plateau[i][colonne].num_joueur != 0) {
                    break;
                }
            }

            // Check horizontal movements
            for (int j = colonne + 1; j < 8; j++) {
                if (plateau[ligne][j].num_joueur == num_joueur) {
                    break;
                }
                plateau[ligne][j].deplacement = '-';
                if (plateau[ligne][j].num_joueur != 0) {
                    break;
                }
            }
            for (int j = colonne - 1; j >= 0; j--) {
                if (plateau[ligne][j].num_joueur == num_joueur) {
                    break;
                }
                plateau[ligne][j].deplacement = '-';
                if (plateau[ligne][j].num_joueur != 0) {
                    break;
                }
            }
            break;
        case '~':
            for (int i = ligne + 1, j = colonne + 1; i < 8 && j < 8; i++, j++) {
                if (plateau[i][j].num_joueur == num_joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }
            for (int i = ligne - 1, j = colonne - 1; i >= 0 && j >= 0; i--, j--) {
                if (plateau[i][j].num_joueur == num_joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }
            for (int i = ligne + 1, j = colonne - 1; i < 8 && j >= 0; i++, j--) {
                if (plateau[i][j].num_joueur == num_joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }
            for (int i = ligne - 1, j = colonne + 1; i >= 0 && j < 8; i--, j++) {
                if (plateau[i][j].num_joueur == num_joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }
            break;
        case '^':
            // vérifier les deplacement possibles
            for (int i = 0; i < 8; i++) {
                int newLigne = ligne + deplacement_cavalier[i][0];
                int newColonne = colonne + deplacement_cavalier[i][1];

                // regarder si la position est dans sur le plateau
                if (newLigne >= 0 && newLigne < 8 && newColonne >= 0 && newColonne < 8 && plateau[newLigne][newColonne].num_joueur != num_joueur) {
                    plateau[newLigne][newColonne].deplacement = '-';
                }
            }
            break;
        case '&':
            for (int i = ligne + 1; i < 8; i++) {
                if (plateau[i][colonne].num_joueur == num_joueur) {
                    break;
                }
                plateau[i][colonne].deplacement = '-';
                if (plateau[i][colonne].num_joueur != 0) {
                    break;
                }
            }
            for (int i = ligne - 1; i >= 0; i--) {
                if (plateau[i][colonne].num_joueur == num_joueur) {
                    break;
                }
                plateau[i][colonne].deplacement = '-';
                if (plateau[i][colonne].num_joueur != 0) {
                    break;
                }
            }
            for (int j = colonne + 1; j < 8; j++) {
                if (plateau[ligne][j].num_joueur == num_joueur) {
                    break;
                }
                plateau[ligne][j].deplacement = '-';
                if (plateau[ligne][j].num_joueur != 0) {
                    break;
                }
            }
            for (int j = colonne - 1; j >= 0; j--) {
                if (plateau[ligne][j].num_joueur == num_joueur) {
                    break;
                }
                plateau[ligne][j].deplacement = '-';
                if (plateau[ligne][j].num_joueur != 0) {
                    break;
                }
            }
            for (int i = ligne + 1, j = colonne + 1; i < 8 && j < 8; i++, j++) {
                if (plateau[i][j].num_joueur == num_joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }
            for (int i = ligne - 1, j = colonne - 1; i >= 0 && j >= 0; i--, j--) {
                if (plateau[i][j].num_joueur == num_joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }
            for (int i = ligne + 1, j = colonne - 1; i < 8 && j >= 0; i++, j--) {
                if (plateau[i][j].num_joueur == num_joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }
            for (int i = ligne - 1, j = colonne + 1; i >= 0 && j < 8; i--, j++) {
                if (plateau[i][j].num_joueur == num_joueur) {
                    break;
                }
                plateau[i][j].deplacement = '-';
                if (plateau[i][j].num_joueur != 0) {
                    break;
                }
            }
            break;
        case '#':
            for (int k = 0; k < 8; k++) {
                int newLigne = ligne + directions[k][0];
                int newColonne = colonne + directions[k][1];
                if (newLigne >= 0 && newLigne < 8 && newColonne >= 0 && newColonne < 8 && plateau[newLigne][newColonne].num_joueur != num_joueur) {
                    plateau[newLigne][newColonne].deplacement = '-';
                }
            }
            break;
        default:
            break;
    }
}

void enlever_piece(elem** plateau, int colonne, int ligne){
    plateau[ligne][colonne].piece = ' ';
    plateau[ligne][colonne].deplacement = ' ';
    plateau[ligne][colonne].num_joueur = 0;
}

void retirer_piece_joueur(elem** plateau, int colonne, int ligne, joueur* j) {
    char piece = plateau[ligne][colonne].piece;
    switch (piece) {
        case '*':
            j->pion--;
            break;
        case '!':
            j->tour--;
            break;
        case '^':
            j->cavalier--;
            break;
        case '&':
            j->reine = 0;
            break;
        case '~':
            j->fou--;
            break;
        default:
            break;
    }
}

void placer_piece(joueur* joueur, elem** plateau, int colonne, int ligne, char piece) {
    plateau[ligne][colonne].piece = piece;
    plateau[ligne][colonne].num_joueur = joueur->numero;
}

void promotion(joueur* joueur, elem** plateau, int row, int column){
    int limit = (joueur->numero == 1) ? 0 : 7 ;
    char choice;
    bool test = false;
    for (int i = 0; i < 8; ++i) {
        if(plateau[limit][i].piece == '*' && (joueur->tour < 2 || joueur->fou < 2 || joueur->cavalier < 2 || joueur->reine == 0)){
            while (!test){
                printf("in what do you want to turn your pawn into? (! = tower, ^ = cavalier, ~ = madman, & = queen\n:");
                scanf(" %c", &choice);
                switch (choice) {
                    case '!':
                        if (joueur->tour < 2) {
                            printf("\nyou chose to turn your pawn into a tower\n");
                            joueur->tour++;
                            test = true;
                        }else{
                            printf("you already have the maximal number of tower\n");
                        }
                        break;
                    case '^':
                        if (joueur->cavalier < 2) {
                            printf("\nyou chose to turn your pawn into a cavalier\n");
                            joueur->cavalier++;
                            test = true;
                        }else{
                            printf("you already have the maximal number of cavalier\n");
                        }
                        break;
                    case '~':
                        if (joueur->fou < 2) {
                            printf("\nyou chose to turn your pawn into a madman\n");
                            joueur->fou++;
                            test = true;
                        }else{
                            printf("you already have the maximal number of madman\n");
                        }
                        break;
                    case '&':
                        if (joueur->reine == 0) {
                            printf("\nyou chose to turn your pawn into a queen\n");
                            joueur->reine++;
                            test = true;
                        }else{
                            printf("you already have the maximal number of queen\n");
                        }
                        break;
                    default:
                        printf("this piece is not valid\n");
                        break;
                }
            }
            plateau[limit][i].piece = choice;
            joueur->pion--;
        }
    }
}
