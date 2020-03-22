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

#ifndef __RESOLUTION__
#define __RESOLUTION__

#include "Laby.h"

typedef struct file_att{
    Coordonnees_t coord;
    struct file_att * suivant; 
}Noeud_File, * File_Att;

/*PARAMETRES : File_Att * fil, int y, int x
 *RETOUR : int, 0 si une erreur se produit, 1 sinon
 *EFFET DE BORD : On modifie fil
 *DESCRIPTION : Cette fonction permet d'allouer la taille nécessaire 
 *pour stoquer un Noeud_File, qui à pour coordonnés (y, x).
 */
int alloue_file(File_Att * fil, int y, int x);

/*PARAMETRES : File_Att * fil, int y, int x
 *RETOUR : int, 0 si une erreur se produit, 1 sinon
 *EFFET DE BORD : On modifie fil
 *DESCRIPTION : Cette fonction ajoute on noeud 
 *de coordonnées (y, x) à la fin de la file d'attente.
 */
int ajoute_file(File_Att * fil, int y, int x);

/*PARAMETRES : File_Att * fil
 *RETOUR : void
 *EFFET DE BORD : On modifie fil
 *DESCRIPTION : Cette fonction enleve le premier noeud de la file d'attente.
 */
void enlever_file(File_Att * fil);

/*PARAMETRES : File_Att * vic, int * taille, File_Att * fil, Laby_t * lab
 *RETOUR : int, 0 si une erreur se produit, 1 sinon
 *EFFET DE BORD : On modifie vic , taille, fil et lab
 *DESCRIPTION : Cette fonction permet de trouver le chemin le 
 *plus court en faisans le parcours en largeur des chemins du labyrinthe.
 *On enleve un noeud de fil, on ajoute ses voisins a fil, on les marque, 
 *et on recommence tant qu'on arrive pas sur la dernierre case du labyrinthe.
 */
int trouve_vic(File_Att * vic, int * taille, File_Att * fil, Laby_t * lab);


#endif