#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    /* Affiche un message d'erreur si l'utilisateur oublie l'argument
     * à passer en ligne de commandes. */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s nombre\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Convertit l'argument passé par l'utilisateur en entier non signé. */
    int32_t au_cas_ou = atoi(argv[1]);
    if (au_cas_ou < 1) {
        fprintf(stderr, " on a dit \"strictement positif\", le nombre! Pas %d...\n", au_cas_ou);
        exit(EXIT_FAILURE);
        /* Tiens et si ca tient pas sur 32 bits? A voir... */
    }
    uint32_t nombre = (uint32_t) au_cas_ou;

    int s=0 ;
    int i ;
    for(i=2 ; i<nombre ; i++ )
    {
        if( nombre%i==0 )
        {
           printf("%d est un diviseur de %d \n",i,nombre);
           s++;
        }


    }
    if(s==0)
     printf("%d est un Nombre Premier \n",nombre);


    return EXIT_SUCCESS;
}
