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

#ifndef __LABY__
#define __LABY__


typedef struct coordonnees_t{
    int x;
    int y;
}Coordonnees_t;

typedef struct{
    int murEst;
    int murSud;
    int rang;

    /*Pour trouver le chemin victorieux*/
    int marque;
    Coordonnees_t pere;
}Case_t;

typedef struct laby{
    Coordonnees_t taille;
    Case_t ** cases; /* attention murs extremes a conserver*/
}Laby_t;

/*PARAMETRES : Laby_t * lab, int taille_y, int taille_x
 *RETOUR : int, 0 si une erreur se produit, 1 sinon
 *EFFET DE BORD : On modifie lab
 *DESCRIPTION : Cette fonction initialise un labyrinthe 
 *de taille taille_y x taille_x, chaque case à un mur est 
 *et un mur sud et est seul dans son enssemble.
 *Pour le chamin victorieu, on ne marque pas les cases, 
 *et on les définis comme leur propre pere.
 */
int Initialisation(Laby_t * lab, int taille_y, int taille_x);

#endif