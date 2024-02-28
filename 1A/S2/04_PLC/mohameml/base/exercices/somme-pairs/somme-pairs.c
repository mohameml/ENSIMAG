#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


int main(void)
{
    int tab[10];
    int i;
    for(i=0;i<10;i++){
        tab[i]=i*2;


    }
    int s=0 ;
    int somme=0;
    for(s=0 ; s<10 ; s++){
        somme+=tab[s];

    }

    printf("La somme est : %d \n",somme);

    return EXIT_SUCCESS;
}
