#include <stdlib.h>
#include <stdio.h>

#include "../include/Laby.h"

int Initialisation(Laby_t * lab, int taille_y, int taille_x){
	int j, i;

    lab->taille.y = taille_y;
    lab->taille.x = taille_x;

	if((lab->cases = (Case_t **)malloc(lab->taille.y * sizeof(Case_t *))) == NULL)
        return 0;

	for(j = 0; j < lab->taille.y; j++)
		if((lab->cases[j] = (Case_t *)malloc(lab->taille.x * sizeof(Case_t))) == NULL)
            return 0;

    for(j = 0; j < lab->taille.y; j++){
        for(i = 0; i < lab->taille.x; i++){
            lab->cases[j][i].rang = 1;
            lab->cases[j][i].pere.y = j;
            lab->cases[j][i].pere.x = i; 
            lab->cases[j][i].murEst = 1;
            lab->cases[j][i].murSud = 1;
            lab->cases[j][i].marque = 0;
            lab->cases[j][i].pere.y = j;
            lab->cases[j][i].pere.x = i;
        }
    }
    
    return 1;
}