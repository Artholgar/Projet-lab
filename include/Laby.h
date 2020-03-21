
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

    /*Pour trouver le chemin victorieu*/
    int marque;
    Coordonnees_t pere;
}Case_t;

typedef struct laby{
    Coordonnees_t taille;
    Case_t ** cases; /* attention murs extremes a conserver*/
}Laby_t;

int Initialisation(Laby_t * lab, int taille_y, int taille_x);

#endif