#include <stdio.h>
#include <stdlib.h>  // Utiliser #include <stdlib.h> pour malloc et free
#include "affichage.h"
#include "plateau.h"
#include "partie.h"

int main() {
    joueur joueur1 = {
            .prenom = "lucas",
            .numero = 1,
            .pion = 8,
            .cavalier = 2,
            .tour = 2,
            .fou = 2,
            .reine = 1,
            .roi = 1
    };

    joueur joueur2 = {
            .prenom = "christophe",
            .numero = 2,
            .pion = 8,
            .cavalier = 2,
            .tour = 2,
            .fou = 2,
            .reine = 1,
            .roi = 1
    };

    joueur* pj1 = &joueur1;
    joueur* pj2 = &joueur2;

    // Allocation de mémoire pour chaque ligne
    elem** plateau = (elem**)malloc(8 * sizeof(elem*));
    if (!plateau) {
        // Gestion de l'échec d'allocation
        fprintf(stderr, "Erreur d'allocation de mémoire pour plateau.\n");
        exit(EXIT_FAILURE);
    }

    // Allocation de mémoire pour chaque colonne
    for (int i = 0; i < 8; ++i) {
        plateau[i] = (elem*)malloc(8 * sizeof(elem));
        if (!plateau[i]) {
            // Gestion de l'échec d'allocation
            fprintf(stderr, "Erreur d'allocation de mémoire pour plateau[%d].\n", i);

            // Libération de la mémoire allouée précédemment
            for (int j = 0; j < i; ++j) {
                free(plateau[j]);
            }
            free(plateau);

            exit(EXIT_FAILURE);
        }
    }

    partie partie_echec = {
            .plateau = plateau, .joueur1 = pj1, .joueur2 = pj2
    };

    // Choix du mode de jeu
    char choix;
    do {
        printf("Choisissez le mode de jeu :\n");
        printf("1 VS 1: tapez '1'\n");
        printf("Jouer contre le bot: tapez '2'\n");
        printf("Quitter le jeu: tapez '3'\n");
        scanf(" %c", &choix);  // Notez l'espace avant %c pour ignorer les espaces, les sauts de ligne, etc.

        switch (choix) {
            case '3':
                printf("Vous quittez le jeu d'echec, au revoir!\n");
                break;
            case '1':
                printf("Vous lancez une partie en 1V1!\n\n");
                initialiser_plateau(partie_echec.plateau);
                game(partie_echec, 1);
                break;
            case '2':
                printf("Vous lancez une partie contre le bot!\n");
                // Ajoutez ici l'appel à la fonction pour jouer contre le bot si elle est implémentée
                break;
            default:
                printf("Choix invalide. Veuillez choisir a nouveau.\n");
                break;
        }

    } while (choix != '3');  // Utilisez une boucle do-while pour continuer tant que l'utilisateur ne choisit pas de quitter

    // Libération de la mémoire allouée
    for (int i = 0; i < 8; ++i) {
        free(plateau[i]);
    }

    // Libération du tableau de pointeurs
    free(plateau);

    return 0;
}
