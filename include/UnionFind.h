/* Auteurs : G. MULIER, A. PAIRAUD
 * Creation : 06-03-2020
 * Modifications : 06-03-2020
 */

#ifndef __UNIONFIND__
#define __UNIONFIND__

#include "Laby.h"

Coordonnees_t TrouveCompresse(Case_t ** cases, int coord_y, int coord_x);

int FusionRang(Case_t ** cases, int coord_y_un, int coord_x_un, int coord_y_deux, int coord_x_deux);

#endif