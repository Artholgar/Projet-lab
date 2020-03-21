#ifndef __RESOLUTION__
#define __RESOLUTION__

#include "Laby.h"

typedef struct file_att{
    Coordonnees_t coord;
    struct file_att * suivant; 
}Noeud_File, * File_Att;

int alloue_file(File_Att * fil, int y, int x);

int ajoute_file(File_Att * fil, int y, int x);

void enlever_file(File_Att * fil);

int trouve_vic(File_Att * vic, int * taille, File_Att * fil, Laby_t * lab);


#endif