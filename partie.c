#include "partie.h"
#include "plateau.h"
#include "verification.h"
#include "affichage.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void game(partie partie, int mode) {
    int tour = 0;
    bool checkmate = false;
    joueur loser, winner;
    if(mode == 1){
        while (!checkmate) {
            loser = player_turn(partie, tour, &checkmate);
            tour++;
        }
    }else{
        while (!checkmate) {
            loser = player_turn(partie, tour, &checkmate);
            loser = bot_turn(partie, &checkmate);
            tour = tour + 2;
        }
    }
    reinitialiser_deplacement(partie.plateau);
    afficher_plateau(partie.plateau);
    printf("--- CHECKMATE ---");
    printf("\n%s est nul au echec!\n\n", loser.prenom);
}


joueur player_turn(partie partie, int tour, bool* checkmate) {

    char coordonnees[5];
    int num_colonne1 = 0, num_ligne1 = 0, num_colonne2 = 0, num_ligne2 = 0;
    char piece;
    elem** plateau = partie.plateau;
    elem** plateau_test = dupliquer_plateau(partie.plateau); // Fonction à implémenter : dupliquer_plateau
    joueur* joueur_actif = (tour % 2 == 0) ? partie.joueur1 : partie.joueur2;
    joueur* joueur_inactif = (tour % 2 == 0) ? partie.joueur2 : partie.joueur1;
    reset_screen();
    printf("\nLancement du tour numero %d", tour + 1);
    printf(", le joueur actif est %s : ", joueur_actif->prenom);
    bool echec = verifier_echec(joueur_actif, joueur_inactif, plateau, 1);
    if (echec){
        if(verif_checkmate(plateau, joueur_actif, joueur_inactif)){
            *checkmate = true;
            return *joueur_actif;
        }
    }
    afficher_pieces_joueur(joueur_actif);

    do{
        do {
            do {
                reinitialiser_deplacement(plateau);
                plateau_test = dupliquer_plateau(plateau);
                afficher_plateau(plateau);
                vider_buffer();
                printf("Entrez les coordonnees de la piece a deplacer: ");
                scanf("%s", coordonnees);
                coordonnees[0] = toupper(coordonnees[0]);
                num_colonne1 = coordonnees[0] - 'A';
                num_ligne1 = strtol(coordonnees + 1, NULL, 10) - 1;
            } while ((coordonnees[0] < 'A' || coordonnees[0] > 'H' || num_ligne1 < 0 || num_ligne1 > 7) ||
                !verifier_piece(joueur_actif, plateau_test, num_colonne1, num_ligne1));
            piece = plateau_test[num_ligne1][num_colonne1].piece;
            definir_deplacement(joueur_actif, plateau, num_colonne1, num_ligne1);
        }while(!verifier_deplacement(plateau));
        reset_screen();
        do {
            printf("Voici vos deplacements possibles : \n\n");
            afficher_plateau(plateau);
            vider_buffer();
            printf("Entrez les nouvelles coordonnees de la piece: ");
            scanf("%s", coordonnees);
            coordonnees[0] = toupper(coordonnees[0]);
            num_colonne2 = coordonnees[0] - 'A';
            num_ligne2 = strtol(coordonnees + 1, NULL, 10) - 1;

        } while ((coordonnees[0] < 'A' || coordonnees[0] > 'H' || num_ligne2 < 0 || num_ligne2 > 7) ||
                 !verifier_placement(plateau, num_colonne2, num_ligne2));



        enlever_piece(plateau_test, num_colonne1, num_ligne1);
        placer_piece(joueur_actif, plateau_test, num_colonne2, num_ligne2, piece);

    } while (verifier_echec(joueur_actif, joueur_inactif, plateau_test, 1));

    enlever_piece(plateau, num_colonne1, num_ligne1);
    retirer_piece_joueur(plateau, num_colonne2, num_ligne2, joueur_inactif);
    placer_piece(joueur_actif, plateau, num_colonne2, num_ligne2, piece);
    reinitialise_check_msg(plateau);
    // Libérer la mémoire du plateau de test
    liberer_plateau(plateau_test); // Fonction à implémenter : liberer_plateau
    verifier_promotion(joueur_actif, plateau);
    return *joueur_actif;
}

// Fonction pour vider le tampon d'entree
void vider_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

joueur bot_turn(partie game,  bool* checkmate){

}