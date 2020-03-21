
#ifndef __AFFICHE__
#define __AFFICHE__

#include "Laby.h"
#include "Resolution.h"

void afficher_graph(Laby_t lab, int fenetre_y, int fenetre_x);

void afficher_ascii(Laby_t lab);

void afficher_utf8(Laby_t lab);

void affiche_garph_victor(File_Att vic, Laby_t lab, int fenetre_y, int fenetre_x);

#endif