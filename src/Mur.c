#include <stdlib.h>
#include <stdio.h>

#include "../include/Mur.h"

int alloue_lst_mur(Liste_Mur * lst, int coord_y, int coord_x, int mur){

    if((*lst = (Cellule_Mur *)malloc(sizeof(Cellule_Mur))) == NULL)
        return 0;

    (*lst)->cas.y = coord_y;
    (*lst)->cas.x = coord_x;
    (*lst)->suivant = NULL;
    return 1;
}


int init_liste_murs(Laby_t lab, Liste_Mur * lst_mur_est, Liste_Mur * lst_mur_sud, int * nb_mur_est, int * nb_mur_sud){
    int i, j;
    Liste_Mur ptr_mur_est, ptr_mur_sud;


    for(j = 0; j < lab.taille.y; j++){
        for(i = 0; i < lab.taille.x; i++){
            if(j == 0 && i == 0){
                if(lab.taille.x > 1){
                    if(alloue_lst_mur(lst_mur_est, 0, 0, lab.cases[0][0].murEst) == 0)
                        return 0;
                    *nb_mur_est += 1;
                }
                
                if(lab.taille.y > 1){
                    if(alloue_lst_mur(lst_mur_sud, 0, 0, lab.cases[0][0].murSud) == 0)
                        return 0;
                    *nb_mur_sud += 1;
                }

                ptr_mur_est = *lst_mur_est;
                ptr_mur_sud = *lst_mur_sud;
            }else{
                if(i < lab.taille.x - 1){
                    if(alloue_lst_mur(&(ptr_mur_est->suivant), j, i, lab.cases[j][i].murEst) == 0)
                        return 0;
                    *nb_mur_est += 1;
                    ptr_mur_est = ptr_mur_est->suivant;
                }
                if(j < lab.taille.y - 1){
                    if(alloue_lst_mur((&ptr_mur_sud->suivant), j, i, lab.cases[j][i].murSud) == 0)
                        return 0;
                    *nb_mur_sud += 1;
                    ptr_mur_sud = ptr_mur_sud->suivant;
                }
            }
        }
    }
    return 1;
}

void retirer_mur_alea_V1(Laby_t * lab, int unique, int * nb_fusions){
    int valide, coor_y, coor_x, sud_ou_est;
    Coordonnees_t trv_cmp_un, trv_cmp_deux;

    if((*lab).taille.y <= 1 && (*lab).taille.x <= 1)
        return ;

    valide = 0;
    while(!valide){
        coor_y = rand() % lab->taille.y;
        coor_x = rand() % lab->taille.x;

        sud_ou_est = rand() % 2;

        if(sud_ou_est == 0 && coor_x < lab->taille.x - 1 && lab->cases[coor_y][coor_x].murEst == 1){
            trv_cmp_un = TrouveCompresse(lab->cases, coor_y, coor_x);
            trv_cmp_deux = TrouveCompresse(lab->cases, coor_y, coor_x + 1);

            if(!unique || trv_cmp_un.y != trv_cmp_deux.y || trv_cmp_un.x != trv_cmp_deux.x){
                *nb_fusions += FusionRang(lab->cases, coor_y, coor_x, coor_y, coor_x + 1);
                lab->cases[coor_y][coor_x].murEst = 0;
                valide = 1;
            }
        }else if(coor_y < lab->taille.y - 1 && lab->cases[coor_y][coor_x].murSud == 1){
            trv_cmp_un = TrouveCompresse(lab->cases, coor_y, coor_x);
            trv_cmp_deux = TrouveCompresse(lab->cases, coor_y + 1, coor_x);

            if(!unique || trv_cmp_un.y != trv_cmp_deux.y || trv_cmp_un.x != trv_cmp_deux.x){
                *nb_fusions += FusionRang(lab->cases, coor_y, coor_x, coor_y + 1, coor_x);
                lab->cases[coor_y][coor_x].murSud = 0;
                valide = 1;
            }
        }
    }
}

void retirer_mur_alea(Laby_t * lab, Liste_Mur * lst_mur_est, Liste_Mur * lst_mur_sud, int unique, int * nb_fusions, int * nb_mur_est, int * nb_mur_sud){
    int valide, sud_ou_est, taille_parcour, i;
    Coordonnees_t trv_cmp_un, trv_cmp_deux;
    Liste_Mur ptr_mur, ptr_prec;

    valide = 0;
    while(!valide){

        sud_ou_est = rand() % 2;

        if(*lst_mur_est == NULL){
            sud_ou_est = 1;
        }else if(*lst_mur_sud == NULL){
            sud_ou_est = 0;
        }

        if(sud_ou_est == 0){
            ptr_mur = *lst_mur_est;
            taille_parcour = rand() % *nb_mur_est;
        }else{
            ptr_mur = *lst_mur_sud;
            taille_parcour = rand() % *nb_mur_sud;
        }
        for(i = 0; i < taille_parcour; i++){
            ptr_prec = ptr_mur;
            ptr_mur = ptr_mur->suivant;
        }
        trv_cmp_un = TrouveCompresse(lab->cases, ptr_mur->cas.y, ptr_mur->cas.x);

        if(sud_ou_est == 0)
            trv_cmp_deux = TrouveCompresse(lab->cases, ptr_mur->cas.y, ptr_mur->cas.x + 1);
        else
            trv_cmp_deux = TrouveCompresse(lab->cases, ptr_mur->cas.y + 1, ptr_mur->cas.x);


        if(!unique || trv_cmp_un.y != trv_cmp_deux.y || trv_cmp_un.x != trv_cmp_deux.x){
            *nb_fusions += FusionRang(lab->cases, trv_cmp_un.y, trv_cmp_un.x, trv_cmp_deux.y, trv_cmp_deux.x);

            if(sud_ou_est == 0)
                lab->cases[ptr_mur->cas.y][ptr_mur->cas.x].murEst = 0;
            else
                lab->cases[ptr_mur->cas.y][ptr_mur->cas.x].murSud = 0;

            valide = 1;

        }

        if(taille_parcour == 0){
            if(sud_ou_est == 0){
                ptr_prec = *lst_mur_est;
                *lst_mur_est = ptr_mur->suivant; 
                *nb_mur_est -= 1;
            }else{
                ptr_prec = *lst_mur_sud;
                *lst_mur_sud = ptr_mur->suivant; 
                *nb_mur_sud -= 1;
            }
            free(ptr_prec);
        }else{
            ptr_prec->suivant = ptr_mur->suivant;
            if(sud_ou_est == 0){   
                *nb_mur_est -= 1;
            }else{
                *nb_mur_sud -= 1;
            }
            free(ptr_mur);
        }
    }
}