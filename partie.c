#include "partie.h"
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
    int ligne, num_colonne1, num_ligne1,num_colonne2, num_ligne2;
    char piece;

    do {
        // Demander à l'utilisateur de choisir une pièce tant que la pièce n'est pas valide
        do {
            do {
                printf("Joueur %d, quelle piece souhaitez-vous deplacer?\n", joueur);
                printf("Entrez la colonne (A a H) : ");
                scanf(" %c", &colonne);
                colonne = toupper(colonne);
            } while (colonne < 'A' || colonne > 'H');

            // Convertir la colonne en valeur entière associée
            num_colonne1 = colonne - 'A';

            // demander la ligne et la convertir
            do {
                printf("Entrez la ligne (1 a 8) : ");
                scanf("%d", &ligne);
                printf("\n");
            } while (ligne < 1 || ligne > 8);
            num_ligne1 = ligne - 1;

        } while (!verifier_piece(joueur, plateau, num_colonne1, num_ligne1));

        piece = plateau[num_ligne1][num_colonne1].piece;
        definir_deplacement(joueur, plateau, num_colonne1, num_ligne1);
    }while(!verifier_deplacement(plateau));

    printf("Voici vos deplacements possibles: \n\n");
    afficher_plateau(plateau);
    printf("Veuillez choisir ou vous voulez deplacer votre piece.\n");
    do {
        printf("Entrez la colonne (A a H) : ");
        scanf(" %c", &colonne);
        colonne = toupper(colonne);
        num_colonne2 = colonne - 'A';

        // Boucle pour la nouvelle ligne
        do {
            printf("Entrez la nouvelle ligne (1 a 8) : ");
            scanf("%d", &ligne);
            printf("\n");
        } while (ligne < 1 || ligne > 8);

        num_ligne2 = ligne - 1;

    } while (!verifier_placement(plateau, num_colonne2, num_ligne2));

    reinitialiser_deplacement(plateau);
    enlever_piece(plateau, num_colonne1, num_ligne1);
    placer_piece(joueur, plateau, num_colonne2, num_ligne2, piece);
}
