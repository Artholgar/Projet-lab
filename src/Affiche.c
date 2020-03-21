#include <stdio.h>
#include <MLV/MLV_all.h>

#include "../include/Affiche.h"

char* intersections[2][2][2][2] = {{{{" ", "╶"}, {"╴", "─"}}, {{"╵", "└"},{"┘", "┴"}}}, {{{"╷", "┌"},{"┐", "┬"}}, {{"│", "├"}, {"┤", "┼"}}}};

void afficher_graph(Laby_t lab, int fenetre_y, int fenetre_x){    
    int j, i;

    for(j = 0; j < lab.taille.y; j++){
        for(i = 0; i < lab.taille.x; i++){
            if(j == 0){
                MLV_draw_line(i * (fenetre_x / (float)lab.taille.x), j * (fenetre_y / (float)lab.taille.y), (i + 1) * (fenetre_x / (float)lab.taille.x), j * (fenetre_y / (float)lab.taille.y), MLV_COLOR_BLACK);
            }
            if(i == 0 && j != 0){
                MLV_draw_line(i * (fenetre_x / (float)lab.taille.x), j * (fenetre_y / (float)lab.taille.y), i * (fenetre_x / (float)lab.taille.x), (j + 1) * (fenetre_y / (float)lab.taille.y), MLV_COLOR_BLACK);
            }
            if(lab.cases[j][i].murEst == 1 && (j != lab.taille.y - 1 || i != lab.taille.x - 1)){
                MLV_draw_line((i + 1) * (fenetre_x / (float)lab.taille.x) - 1, j * (fenetre_y / (float)lab.taille.y) - 1, (i + 1) * (fenetre_x / (float)lab.taille.x) - 1, (j + 1) * (fenetre_y / (float)lab.taille.y) - 1, MLV_COLOR_BLACK);
            }
            if(lab.cases[j][i].murSud == 1){
                MLV_draw_line(i * (fenetre_x / (float)lab.taille.x) - 1, (j + 1) * (fenetre_y / (float)lab.taille.y) - 1, (i + 1) * (fenetre_x / (float)lab.taille.x) - 1, (j + 1) * (fenetre_y / (float)lab.taille.y) - 1, MLV_COLOR_BLACK);
            }
        }
    }
}

void afficher_ascii(Laby_t lab){
    int j, i;

    for(j = 0; j < lab.taille.y; j++){
        if(j == 0){
            printf("+");
            for(i = 0; i < lab.taille.x; i++){
                printf("--+");
            }
            printf("\n");
        }
        for(i = 0; i < lab.taille.x; i++){
            if(i == 0 && j != 0){
                printf("|");
            }else if(i == 0){
                printf(" ");
            }
            printf("  ");
            if(lab.cases[j][i].murEst == 1 && (j != lab.taille.y - 1 || i != lab.taille.x - 1)){
                printf("|");
            }else{
                printf(" ");
            }
        }
        printf("\n");
        printf("+");
        for(i = 0; i < lab.taille.x; i++){
            if(lab.cases[j][i].murSud == 1){
                printf("--");
            }else{
                printf("  ");
            }
            if(i == lab.taille.x - 1 || j == lab.taille.y - 1 || lab.cases[j][i].murSud == 1 || lab.cases[j][i].murEst == 1 || lab.cases[j][i + 1].murSud == 1 || lab.cases[j + 1][i].murEst == 1)
                printf("+");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void afficher_utf8(Laby_t lab){
    int j, i;
    int b, h, g, d;

    for(j = 0; j < lab.taille.y; j++){
        /*affichagede la premiere ligne*/
        if(j == 0){
            printf("%s", intersections[0][0][0][1]); /*╶*/
            for(i = 0; i < lab.taille.x - 1; i++){
                printf("%s%s", intersections[0][0][1][1], intersections[0][0][1][1]); /*──*/
                if(lab.cases[j][i].murEst == 1){
                    printf("%s", intersections[1][0][1][1]); /*┬*/
                }else{
                    printf("%s", intersections[0][0][1][1]); /*─*/
                }
            }
            printf("%s%s%s", intersections[0][0][1][1], intersections[0][0][1][1], intersections[1][0][1][0]); /*──┐*/
            printf("\n");
        }
        /*affichage des milieux de lignes*/
        for(i = 0; i < lab.taille.x; i++){
            if(i == 0 && j != 0){
                printf("%s", intersections[1][1][0][0]); /*│*/
            }else if(i == 0){
                printf("%s", intersections[0][0][0][0]); /* */
            }
            printf("%s%s", intersections[0][0][0][0], intersections[0][0][0][0]); /*  */

            if(lab.cases[j][i].murEst == 1 && (j != lab.taille.y - 1 || i != lab.taille.x - 1)){
                printf("%s", intersections[1][1][0][0]); /*│*/
            }else{
                printf("%s", intersections[0][0][0][0]); /* */
            }
        }
        printf("\n");

        /*affichage du premier caractere de la linge de murs horizontaux (premiere colonne)*/
        i = 0;
        if(lab.cases[j][i].murSud == 1){
            if(j != lab.taille.y - 1){
                printf("%s", intersections[1][1][0][1]); /*├*/
            }else{
                printf("%s", intersections[0][1][0][1]); /*└*/
            }
        }else
            printf("%s", intersections[1][1][0][0]); /*│*/

        /*affichage des murs horizontaux*/
        for(i = 0; i < lab.taille.x; i++){
            if(lab.cases[j][i].murSud == 1){
                printf("%s%s", intersections[0][0][1][1], intersections[0][0][1][1]); /*──*/
            }else{
                printf("%s%s", intersections[0][0][0][0], intersections[0][0][0][0]); /*  */
            }
            /*Si on est sur la dernierre colonne*/
            if(i == lab.taille.x - 1){
                if(j == lab.taille.y - 1)
                    printf("%s", intersections[0][0][1][0]); /*╴*/
                else{
                    if(lab.cases[j][i].murSud == 1)
                        printf("%s", intersections[1][1][1][0]); /*┤*/
                    else
                        printf("%s", intersections[1][1][0][0]); /*│*/
                }

            }else if(j == lab.taille.y - 1){

                if(lab.cases[j][i].murEst == 1)
                    printf("%s", intersections[0][1][1][1]); /*┴*/
                else
                    printf("%s", intersections[0][0][1][1]); /*─*/

            }else{

                if(lab.cases[j][i].murEst == 1){
                    h = 1;
                }else{
                    h = 0;
                }
                if(lab.cases[j][i].murSud == 1){
                    g = 1;
                }else{
                    g = 0;
                }
                if(lab.cases[j + 1][i].murEst == 1){
                    b = 1;
                }else{
                    b = 0;
                }
                if(lab.cases[j][i + 1].murSud == 1){
                    d = 1;
                }else{
                    d = 0;
                }
                printf("%s", intersections[b][h][g][d]); /**/

            }
        }
        printf("\n");
    }
}

void affiche_garph_victor(File_Att vic, Laby_t lab, int fenetre_y, int fenetre_x){

    while(vic != NULL){
        MLV_draw_filled_rectangle(vic->coord.x * (fenetre_x / (float)lab.taille.x),  vic->coord.y * (fenetre_y / (float)lab.taille.y), (fenetre_x / (float)lab.taille.x), (fenetre_y / (float)lab.taille.y), MLV_COLOR_RED); 
        vic = vic->suivant;
    }
}