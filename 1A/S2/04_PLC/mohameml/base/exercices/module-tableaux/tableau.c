#include <stdlib.h>
#include <stdint.h>
#include <stdio.h> 

#include "tableau.h"

void affiche(int32_t tab[], uint32_t taille)
{
    /* A implémenter! */
    int i ;
    for(i=0 ; i<taille-1  ; i++)
    {
        printf("[%d] ", tab[i]);
    }
    printf("[%d] \n", tab[i]);


}

void init_interactive(int32_t tab[], uint32_t taille)
{
    /* A implémenter! */
    char chaine[3];
    fgets(chaine , 3, stdin);


    int i; 
    for(i=0 ; i<taille ; i++)
    {
        tab[i]= atoi(chaine) ;
        fgets(chaine , 3, stdin); ;
        
    }
    tab[i]= atoi(chaine) ; 


}

void init_aleatoire(int32_t tab[], uint32_t taille)
{
    /* A implémenter! */
    int i; 
    for(i=0 ; i<taille ; i++)
    {
        tab[i]=rand();
    }

}

void tri_insertion(int32_t tab[], uint32_t taille)
{
    /* A implémenter! */
    int inter ;
    int position ;
    int i ;
    int j ;
    for(i=0 ; i< taille-1 ; i++)
    {
        position = i ;
        for(j=i+1 ;j<taille ; j++)
        {
            if(tab[j]<tab[position])
            {
                position=j;

            }
        } 
        inter = tab[i];
        tab[i]=tab[position];
        tab[position]=inter ; 
    }
}
