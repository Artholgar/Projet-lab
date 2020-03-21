#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/Resolution.h"

int alloue_file(File_Att * fil, int y, int x){

    if(((*fil) = (File_Att)malloc(sizeof(Noeud_File))) == NULL){
        return 0;
    }

    (*fil)->coord.y = y;
    (*fil)->coord.x = x;
    (*fil)->suivant = NULL; 
    return 1;
}

int ajoute_file(File_Att * fil, int y, int x){
    File_Att ptr_fil;

    if((*fil) == NULL){
        
        if(alloue_file(fil, y, x) == 0){
            return 0;
        }
    }else{
        ptr_fil = (*fil);
        while(ptr_fil->suivant != NULL){
            ptr_fil = ptr_fil->suivant;
        }
        if(alloue_file(&(ptr_fil->suivant), y, x) == 0){
            return 0;
        }
    }
    return 1;
}

void enlever_file(File_Att * fil){
    File_Att tmp;

    assert((*fil) != NULL);

    tmp = (*fil);

    (*fil) = (*fil)->suivant;

    free(tmp);
}

int trouve_vic(File_Att * vic, int * taille, File_Att * fil, Laby_t * lab){
    Coordonnees_t cas;
    File_Att ptr_vic;

    ptr_vic = NULL;

    if((*fil) == NULL){
        return 0;
    }
    
    lab->cases[lab->taille.y - 1][lab->taille.x - 1].marque = 1;

    while((*fil) != NULL){
        cas.y = (*fil)->coord.y;
        cas.x = (*fil)->coord.x;

        enlever_file(fil);

        if(cas.y == 0 && cas.x == 0){
            ajoute_file(vic, cas.y, cas.x);
            (*taille)++;
            break;
        }

        if(cas.y > 0 && lab->cases[cas.y - 1][cas.x].murSud == 0 && lab->cases[cas.y - 1][cas.x].marque == 0){
            ajoute_file(fil, cas.y - 1, cas.x);
            lab->cases[cas.y - 1][cas.x].pere.y = cas.y;
            lab->cases[cas.y - 1][cas.x].pere.x = cas.x;
            lab->cases[cas.y - 1][cas.x].marque = 1;
        }

        if(cas.y < lab->taille.x - 1 && lab->cases[cas.y][cas.x].murSud == 0 && lab->cases[cas.y + 1][cas.x].marque == 0){
            ajoute_file(fil, cas.y + 1, cas.x);
            lab->cases[cas.y + 1][cas.x].pere.y = cas.y;
            lab->cases[cas.y + 1][cas.x].pere.x = cas.x;
            lab->cases[cas.y + 1][cas.x].marque = 1;
        }

        if(cas.x > 0 && lab->cases[cas.y][cas.x - 1].murEst == 0 && lab->cases[cas.y][cas.x - 1].marque == 0){
            ajoute_file(fil, cas.y, cas.x - 1);
            lab->cases[cas.y][cas.x - 1].pere.y = cas.y;
            lab->cases[cas.y][cas.x - 1].pere.x = cas.x;
            lab->cases[cas.y][cas.x - 1].marque = 1;
        }

        if(cas.x < lab->taille.x - 1 && lab->cases[cas.y][cas.x].murEst == 0 && lab->cases[cas.y][cas.x + 1].marque == 0){
            ajoute_file(fil, cas.y, cas.x + 1);
            lab->cases[cas.y][cas.x + 1].pere.y = cas.y;
            lab->cases[cas.y][cas.x + 1].pere.x = cas.x;
            lab->cases[cas.y][cas.x + 1].marque = 1;
        }

        
    }
    
    if((*vic) != NULL){
        ptr_vic = (*vic);
        /*while(lab->cases[ptr_vic->coord.y][ptr_vic->coord.x].pere.y != lab->taille.y - 1 || lab->cases[ptr_vic->coord.y][ptr_vic->coord.x].pere.x != lab->taille.x - 1){*/
        while(ptr_vic->coord.y != lab->taille.y - 1 || ptr_vic->coord.x != lab->taille.x - 1){
            ajoute_file(vic, lab->cases[ptr_vic->coord.y][ptr_vic->coord.x].pere.y, lab->cases[ptr_vic->coord.y][ptr_vic->coord.x].pere.x);
            (*taille)++;
            ptr_vic = ptr_vic->suivant;
        }
        return 1;
    } 

    return 0;
}