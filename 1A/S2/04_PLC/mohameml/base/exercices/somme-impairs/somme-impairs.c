#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define TAILLE_TAB 5000 

void init_tab(uint32_t tab[], size_t length);


uint32_t somme_tab(uint32_t tab[], size_t length);


int main(void)
{
    
    int tab[TAILLE_TAB];
    init_tab( tab,TAILLE_TAB);
    int somme = somme_tab( tab ,TAILLE_TAB);

    printf("La somme des elemnts de tab est : %d \n",somme);


    

    

    return EXIT_SUCCESS;
}

void init_tab(uint32_t tab[], size_t length)
{
    int i ;
    for(i=0; i<length ;i++)
    {
        tab[i]=2*i+1 ;
        

    }
}

uint32_t somme_tab(uint32_t tab[], size_t length)
{
    uint32_t somme=0 ;
    int i=0 ;
    for(i=0 ;i<length ; i++)
    {
        somme+=tab[i];
    }
    return somme ;
}


