#define _XOPEN_SOURCE   600  /*pour enlever le warning de usleep*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <MLV/MLV_all.h>
#include <time.h>

#include "../include/Laby.h"
#include "../include/UnionFind.h"
#include "../include/Mur.h"
#include "../include/Affiche.h"
#include "../include/Resolution.h"

int main(int argc, char ** argv){
    Laby_t lab;
    int i, j, mode, taille_y, taille_x, graine, attente, unique, acces, nb_fusions, nb_mur_est, nb_mur_sud, fenetre_x, fenetre_y, mur, victor, taille_chemin;
    Coordonnees_t test_vic_un, test_vic_deux;
    MLV_Keyboard_button touche;
    Liste_Mur lst_mur_est, lst_mur_sud;
    File_Att fil, vic;

    /*Initialisation des parametres*/
    lst_mur_est = NULL;
    lst_mur_sud = NULL;
    mode = 0;
    graine = time(NULL);
    attente = -1;
    unique = 0;
    acces = 0;
    taille_y = 5;
    taille_x = 5;
    fenetre_y = 500;
    fenetre_x = 500;
    mur = 0;
    victor = 0;
    fil = NULL;
    vic = NULL;

    /*Modification des parametres, en fonction des arguments donnés au programme*/
    for(i = 1; i < argc; i++){
        if(strncmp(argv[i], "--mode=", 7) == 0){   
            if(strcmp(argv[i] + 7, "texte") == 0){
                mode = 1;
            }else if(strcmp(argv[i] + 7, "utf8") == 0){
                mode = 2;
            }else{
                printf("Erreur : mode invalide\n");
                exit(EXIT_FAILURE);
            }
        }else if(strncmp(argv[i], "--taille=", 9) == 0){   
            if((taille_y = atoi(argv[i] + 9)) > 0){
                j = 0;
                while(argv[i][j] != 'x'){
                    if(argv[i][j] == EOF){
                        printf("Erreur : taille invalide\n");
                        exit(EXIT_FAILURE);
                    }
                    j++;
                }
                if((taille_x = atoi(argv[i] + j + 1)) <= 0){
                    printf("Erreur : taille invalide\n");
                    exit(EXIT_FAILURE);
                }
            }else{
                printf("Erreur : taille invalide\n");
                exit(EXIT_FAILURE);
            }
        }else if(strncmp(argv[i], "--fenetre=", 10) == 0){   
            if((fenetre_y = atoi(argv[i] + 10)) > 0){
                j = 0;
                while(argv[i][j] != 'x'){
                    if(argv[i][j] == EOF){
                        printf("Erreur : taille de fenetre invalide\n");
                        exit(EXIT_FAILURE);
                    }
                    j++;
                }
                if((fenetre_x = atoi(argv[i] + j + 1)) <= 0){
                    printf("Erreur : taille de fenetre invalide\n");
                    exit(EXIT_FAILURE);
                }
            }else{
                printf("Erreur : taille invalide\n");
                exit(EXIT_FAILURE);
            }
        }else if(strncmp(argv[i], "--graine=", 9) == 0){
            if((graine = atoi(argv[i] + 9)) <= 0){
                printf("Erreur : graine invalide\n");
                exit(EXIT_FAILURE);
            }
        }else if(strncmp(argv[i], "--attente=", 10) == 0){
            if((attente = atoi(argv[i] + 10)) <= 0 && strcmp(argv[i] + 10, "0") != 0){
                printf("Erreur : attente invalide\n");
                exit(EXIT_FAILURE);
            }
        }else if(strcmp(argv[i], "--unique") == 0){
            unique = 1;
        }else if(strcmp(argv[i], "--acces") == 0){
            acces = 1;
        }else if(strcmp(argv[i], "--mur") == 0){
            mur = 1;
        }else if(strcmp(argv[i], "--victor") == 0){   
            victor = 1;
        }else{
            printf("Erreur : options invalides\n");
            exit(EXIT_FAILURE);
        }

    }

    srand(graine);
    nb_fusions = 0;
    nb_mur_est = 0;
    nb_mur_sud = 0;

    /*Initialisation de la liste chainée contenant les murs (une liste pour les murs sud et une liste pour les murs est)*/
    if(Initialisation(&lab, taille_y, taille_x) == 0)
        exit(EXIT_FAILURE);   

    if(init_liste_murs(lab, &lst_mur_est, &lst_mur_sud, &nb_mur_est, &nb_mur_sud) == 0)
        exit(EXIT_FAILURE); 

    if(mode == 0){
        MLV_create_window("Laby", "", fenetre_x, fenetre_y);
    }

    do{
        if(attente == 0){
    
            if(mur == 0){
                
                retirer_mur_alea_V1(&lab, unique, &nb_fusions);
            }else{
                retirer_mur_alea(&lab, &lst_mur_est, &lst_mur_sud, unique, &nb_fusions, &nb_mur_est, &nb_mur_sud);
            }
            test_vic_un = TrouveCompresse(lab.cases, 0, 0);
            test_vic_deux = TrouveCompresse(lab.cases, lab.taille.y - 1, lab.taille.x - 1);
        }else{
            if(mode == 0){
                MLV_clear_window(MLV_COLOR_WHITE);
                afficher_graph(lab, fenetre_y, fenetre_x);
                MLV_actualise_window();
            }else if(mode == 1){
                afficher_ascii(lab);
                printf("\n\n");
            }else{
                afficher_utf8(lab);
                printf("\n\n");
            }
            
            if(lst_mur_est != NULL || lst_mur_sud != NULL){
                if(mur == 0){
                    retirer_mur_alea_V1(&lab, unique, &nb_fusions);
                }else{
                    retirer_mur_alea(&lab, &lst_mur_est, &lst_mur_sud, unique, &nb_fusions, &nb_mur_est, &nb_mur_sud);
                }
            }

            test_vic_un = TrouveCompresse(lab.cases, 0, 0);
            test_vic_deux = TrouveCompresse(lab.cases, lab.taille.y - 1, lab.taille.x - 1);

            if(attente == -1){
                if(mode == 0){
                    MLV_wait_keyboard_or_mouse(&touche, NULL, NULL, NULL, NULL);
                }else{
                    getchar();
                }
            }else{
                usleep(attente * 1000);
            }
        }

    }while(test_vic_un.x != test_vic_deux.x || test_vic_un.y != test_vic_deux.y || (acces && nb_fusions != (lab.taille.y * lab.taille.x) - 1));

    if(mode == 0){
        MLV_clear_window(MLV_COLOR_WHITE);
        afficher_graph(lab, fenetre_y, fenetre_x);
        MLV_actualise_window();
        MLV_wait_keyboard_or_mouse(&touche, NULL, NULL, NULL, NULL);
    }else if(mode == 1){
        afficher_ascii(lab);
    }else{
        afficher_utf8(lab);
    }

    if(victor){
        ajoute_file(&fil, lab.taille.y - 1, lab.taille.x - 1);
        taille_chemin = 0;
        lab.cases[lab.taille.y - 1][lab.taille.x - 1].marque = 1;
        trouve_vic(&vic, &taille_chemin, &fil, &lab);

        if(mode == 0){
            MLV_clear_window(MLV_COLOR_WHITE);
            affiche_garph_victor(vic ,lab, fenetre_y, fenetre_x);
            afficher_graph(lab, fenetre_y, fenetre_x);
            MLV_actualise_window();
            MLV_wait_keyboard_or_mouse(&touche, NULL, NULL, NULL, NULL);
        }else{
            while(vic != NULL){
                printf("%d, %d\n", vic->coord.y, vic->coord.x);
                vic = vic->suivant;
            }
            printf("%d\n", taille_chemin);
        }
    }

    return 0;
}