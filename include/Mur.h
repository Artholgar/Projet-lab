/*Auteurs       : Guillaume MULIER, Arthur PAIRAUD
 *Création      : 24-02-2020
 *Modifications : 24-02-2020
 *                28-02-2020
 *                29-02-2020
 *                01-03-2020
 *                08-03-2020
 *                14-03-2020
 *                15-03-2020
 *                16-03-2020
 *                19-03-2020
 *                20-03-2020
 *                21-03-2020
 *                22-03-2020
 */

#ifndef __MUR__
#define __MUR__

#include "Laby.h"
#include "UnionFind.h"

typedef struct lst_mur{
    Coordonnees_t cas;
    int mur;
    struct lst_mur * suivant;
}Cellule_Mur, * Liste_Mur;

/*PARAMETRES : Liste_Mur * lst, int coord_x, int coord_y
 *RETOUR : int, 0 si une erreur se produit, 1 sinon
 *EFFET DE BORD : On modifie lst
 *DESCRIPTION : Cette fonction alloue de la place pour initialister
 une Cellule_Mur aux coordonnées coord_y x coord_x.
 */
int alloue_lst_mur(Liste_Mur * lst, int coord_y, int coord_x);

/*PARAMETRES : Laby_t lab, Liste_Mur * lst_mur_est, Liste_Mur * lst_mur_sud, int * nb_mur_est, int * nb_mur_sud
 *RETOUR : int, 0 si une erreur se produit, 1 sinon
 *EFFET DE BORD : On modifie lst_mur_est, lst_mur_sud, nb_mur_est et nb_mur_sud
 *DESCRIPTION : Cette fonction initialise deux Liste_Mur, lst_mur_est contient 
 *tous les murs est du labyrinthe et lst_mur_sud contient tous les murs sud du labyrinthe.
 *nb_mur_est et nb_mur_sud représentent les tailles de ces deux listes.
 */
int init_liste_murs(Laby_t lab, Liste_Mur * lst_mur_est, Liste_Mur * lst_mur_sud, int * nb_mur_est, int * nb_mur_sud);

/*PARAMETRES : Laby_t * lab, int unique, int * nb_fusions
 *RETOUR : int, 0 si une erreur se produit, 1 sinon
 *EFFET DE BORD : On modifie lab et nb_fusions
 *DESCRIPTION : Cette fonction permet de retirer aléatoirement un mur du labyrinthe.
 *On prend une case au hasard et on essaye d'enlever son mur est ou son mur sud aléatoirement,
 *si il n'y a pas de mur à cette endroit, ou si on veut un chemin unique et que le mur ne respecte 
 *pas les regles du chemin unique, on reprend au hasard un mur.
 */
void retirer_mur_alea_V1(Laby_t * lab, int unique, int * nb_fusions);

/*PARAMETRES : Laby_t * lab, Liste_Mur * lst_mur_est, Liste_Mur * lst_mur_sud, int unique, int * nb_fusions, int * nb_mur_est, int * nb_mur_sud
 *RETOUR : int, 0 si une erreur se produit, 1 sinon
 *EFFET DE BORD : On modifie lab, nb_fusions, lst_mur_est, lst_mur_sud, nb_mur_est et nb_mur_sud
 *DESCRIPTION : Cette fonction permet de retirer aléatoirement un mur du labyrinthe.
 *On choisis aléatoirement entre les murs est et les murs sud, on prend un entier inferieur à 
 *la taille de la liste et on retire le mur de la liste.
 */
void retirer_mur_alea(Laby_t * lab, Liste_Mur * lst_mur_est, Liste_Mur * lst_mur_sud, int unique, int * nb_fusions, int * nb_mur_est, int * nb_mur_sud);

#endif