
#ifndef __MUR__
#define __MUR__

#include "Laby.h"
#include "UnionFind.h"

typedef struct lst_mur{
    Coordonnees_t cas;
    int mur;
    struct lst_mur * suivant;
}Cellule_Mur, * Liste_Mur;

int alloue_lst_mur(Liste_Mur * lst, int coord_x, int coord_y, int mur);

int init_liste_murs(Laby_t lab, Liste_Mur * lst_mur_est, Liste_Mur * lst_mur_sud, int * nb_mur_est, int * nb_mur_sud);

void retirer_mur_alea_V1(Laby_t * lab, int unique, int * nb_fusions);

void retirer_mur_alea(Laby_t * lab, Liste_Mur * lst_mur_est, Liste_Mur * lst_mur_sud, int unique, int * nb_fusions, int * nb_mur_est, int * nb_mur_sud);

#endif