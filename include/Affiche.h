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

#ifndef __AFFICHE__
#define __AFFICHE__

#include "Laby.h"
#include "Resolution.h"

/*PARAMETRES : Laby_t lab, int fenetre_y, int fenetre_x
 *RETOUR : void
 *EFFET DE BORD : Affiche sur une fenetre MLV
 *DESCRIPTION : Cette fonction permet d'afficher le labyrinthe 
 *sur une fenetre MLV de taille fenetre_y x fenetre_x.
 */
void afficher_graph(Laby_t lab, int fenetre_y, int fenetre_x);

/*PARAMETRES : Laby_t lab
 *RETOUR : void
 *EFFET DE BORD : Affiche sur la sortie standard
 *DESCRIPTION : Cette fonction permet d'afficher le labyrinthe 
 *avec des caracteres ascii sur la terminal.
 */
void afficher_ascii(Laby_t lab);

/*PARAMETRES : Laby_t lab
 *RETOUR : void
 *EFFET DE BORD : Affiche sur la sortie standard
 *DESCRIPTION : Cette fonction permet d'afficher le labyrinthe 
 *avec des caracteres utf8 sur la terminal.
 */
void afficher_utf8(Laby_t lab);

/*PARAMETRES : File_Att vic, Laby_t lab, int fenetre_y, int fenetre_x
 *RETOUR : void
 *EFFET DE BORD : Affiche sur une fenetre MLV
 *DESCRIPTION : Cette fonction permet d'afficher la chemin victorieux du labirinthe
 *sur une fenetre MLV de taille fenetre_y x fenetre_x.
 */
void affiche_garph_victor(File_Att vic, Laby_t lab, int fenetre_y, int fenetre_x);

#endif