# Projet-lab

Projet de labyrinthe en C.

# Prérequis: 
Instaler la lib MLV

# Instalation de l'application:

~$ make install

# Utilistation:

~$ ./bin/Laby [options]

[options] :

    --mode= : texte -> affichage ascii
              utf8 -> affichage utf8
   
    --taille=[taille_y]x[taille_x] -> définis la taille du labyrinte
    
    --fenetre=[taille_fenetre_y]x[taille_fenetre_x] -> définis la taille de la fenetre MLV en pixels
    
    --graine=[graine] -> définis la graine utilisée pour génerer le labyrinthe
    
    --attente=[nb_ms] -> définis le nb de ms entre deux suppressions de murs
    
    --unique -> un seul chemin valide pour le labyrinthe
    
    --acces -> toutes les cases du labyrinthe accessibles
    
    --mur -> uniliser une autre structure pour stoquer les murs
    
    --victor -> affiche le chemin victorieux du labyrinthe
