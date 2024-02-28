#include <stdlib.h>

#include "tableau.h"
#include <stdio.h>

int main(void)
{
    const int taille = 10;
    int tab[10];
    printf("--------------init_interactive---------------------------\n");
    init_interactive(tab , taille );
    affiche(tab, taille);
    
    
    printf("------------------Tri_de_la_table ---------------------------\n");
    tri_insertion(tab ,taille);
    affiche(tab , taille );


    printf("------------------------init_aleatoire---------------------------------\n");
    init_aleatoire(tab, taille);
    affiche(tab , taille );




    return EXIT_SUCCESS;
}
