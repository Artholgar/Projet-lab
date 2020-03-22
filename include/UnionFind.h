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

#ifndef __UNIONFIND__
#define __UNIONFIND__

#include "Laby.h"

/*PARAMETRES : Case_t ** cases, int coord_y, int coord_x
 *RETOUR : Coordonnees_t du représentant de la case.
 *EFFET DE BORD : On modifie cases
 *DESCRIPTION : Cette fonction trouve le représentant de la case aux coordonnées coord_y, coord_x
 *En parcourant l'arbre, on compresse le chemin.
 */
Coordonnees_t TrouveCompresse(Case_t ** cases, int coord_y, int coord_x);

/*PARAMETRES : Case_t ** cases, int coord_y_un, int coord_x_un, int coord_y_deux, int coord_x_deux
 *RETOUR : int, 0 si une erreur se produit, 1 sinon
 *EFFET DE BORD : On modifie cases
 *DESCRIPTION : Cette fonction fusionne deux enssembles, si ils ne sont pas deja le même enssemble.
 *On met l'enssemble le plus petit dans l'ensssemble le plus grand.
 */
int FusionRang(Case_t ** cases, int coord_y_un, int coord_x_un, int coord_y_deux, int coord_x_deux);

#endif