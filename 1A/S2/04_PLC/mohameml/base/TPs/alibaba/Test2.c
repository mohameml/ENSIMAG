
#include <stdlib.h>
#include <stdint.h>
#include <criterion/criterion.h>

#include "ldc.h"


int main(void)
{
    struct ldc liste ;
    liste.suiv=NULL ;
    liste.prev=NULL ;
    liste.numero=1 ;
    struct ldc** pl;
    *pl=&liste ;
    
    ldc_insere_fin( pl,   (uint32_t)2);
    ldc_insere_fin( pl,   (uint32_t)3);
    ldc_insere_fin( pl,   (uint32_t)4);
    ldc_insere_fin( pl,   (uint32_t)5);
    ldc_affiche(&liste);


    return 0 ;

}