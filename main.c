
#include <stdbool.h>
#include <stdlib.h>  // Utiliser #include <stdlib.h> pour malloc et free
#include "affichage.h"
#include "plateau.h"
#include "partie.h"

#define pion 1

int main() {
    // Déclaration d'un tableau de pointeurs vers la structure elem
    elem** plateau = (elem**)malloc(8 * sizeof(elem*));

    // Allocation de mémoire pour chaque ligne
    for (int i = 0; i < 8; ++i) {
        plateau[i] = (elem*)malloc(8 * sizeof(elem));
    }

    // Appel de la fonction pour initialiser le plateau
    initialiser_plateau(plateau);
    reinitialiser_deplacement(plateau);
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
                partie_pvp(plateau);
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