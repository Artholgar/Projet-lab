#include <stdio.h>
#include "../include/UnionFind.h"

Coordonnees_t TrouveCompresse(Case_t ** cases, int coord_y, int coord_x){
	if(cases[coord_y][coord_x].pere.y != coord_y || cases[coord_y][coord_x].pere.x != coord_x){
		cases[coord_y][coord_x].pere = TrouveCompresse(cases, cases[coord_y][coord_x].pere.y, cases[coord_y][coord_x].pere.x);
	}
	return cases[coord_y][coord_x].pere;
}

int FusionRang(Case_t ** cases, int coord_y_un, int coord_x_un, int coord_y_deux, int coord_x_deux){
	Coordonnees_t racine_un;
	Coordonnees_t racine_deux;

	racine_un = TrouveCompresse(cases, coord_y_un, coord_x_un);
	racine_deux = TrouveCompresse(cases, coord_y_deux, coord_x_deux);
    
	if(racine_un.y != racine_deux.y || racine_un.x != racine_deux.x){
		if(cases[racine_un.y][racine_un.x].rang <= cases[racine_deux.y][racine_deux.x].rang)
			cases[racine_un.y][racine_un.x].pere = racine_deux;
		else{
			cases[racine_deux.y][racine_deux.x].pere = racine_un;
			if(cases[racine_un.y][racine_un.x].rang == cases[racine_deux.y][racine_deux.x].rang){
				cases[racine_un.y][racine_un.x].rang++;
			} 
		}
        return 1;
	}
    return 0;
}