#include "partie.h"
#include "affichage.h"
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

void partie_pvp(elem** plateau) {
    int tours = 0, joueur;
    bool partie_gagne = false;

    while (!partie_gagne) {
        afficher_plateau(plateau);

        // Déterminez le joueur actuel en fonction du nombre de tours
        joueur = (tours % 2 == 0) ? 1 : 2;

        jouer_tours(joueur, plateau);
        tours++;
    }
}

void jouer_tours(int joueur, elem** plateau) {
    char colonne;
    int ligne, num_colonne, num_ligne;

    do {
        // Demander à l'utilisateur de choisir une pièce tant que la pièce n'est pas valide
        do {
            printf("Joueur %d, quelle piece souhaitez-vous deplacer?\n", joueur);
            printf("Entrez la colonne (A a H) : ");
            scanf(" %c", &colonne);
            colonne = toupper(colonne);
        } while (colonne < 'A' || colonne > 'H');

        // Convertir la colonne en valeur entière associée
        num_colonne = colonne - 'A';

        // Boucle pour la ligne
        do {
            printf("Entrez la ligne (1 a 8) : ");
            scanf("%d", &ligne);
            printf("\n");
        } while (ligne < 1 || ligne > 8);
        num_ligne = ligne - 1;
    } while (!verifier_piece(joueur, plateau, num_colonne, num_ligne));
}