#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ldc.h"

/* Implémentation du module liste doublement chaînée circulaire */

// Insère la valeur n en fin de la liste pointée par pl
void ldc_insere_fin(struct ldc** pl, uint32_t n){
    struct ldc sent ={-1 , *pl , NULL };
    struct  ldc* p = &sent ;
    while(p->suiv!=sent.suiv){
        p=p->suiv ;
    }
    p->suiv = malloc(sizeof(struct ldc));
    p->suiv->numero=n;
    p->suiv->suiv=sent.suiv ;
    p->suiv->prev = p ;
    sent.suiv->prev=p->suiv ;
    *pl=sent.suiv ;
}

void ldc_affiche(struct ldc* l)
{
    struct ldc *p=l;

    while(p->suiv!=l){
        printf("%d -> ",p->numero);
        p = p->suiv ;

    }
    printf("%d ",p->numero);
    printf("FIN \n");
}
uint32_t ldc_taille(struct ldc* l)
{
    uint32_t  taille =1 ;
    struct ldc *p=l;

    while(p->suiv!=l){
        taille++ ;
        p = p->suiv ;

    }
    return taille ;

}

struct ldc* ldc_recupere_nieme(struct ldc* e, uint8_t n)
{
    uint8_t  compteur =1 ;
    struct ldc *p=e;

    while(compteur != n){
        compteur++ ;
        p = p->suiv ;

    }

    return p->suiv ;


}

// Supprime l'élément e de la liste pointée par pl
// et libère la mémoire associée à e.
// préconditions:
//   - *pl non vide
//   - e non NULL
//   - e dans *pl
void ldc_supprime(struct ldc** pl, struct ldc* e)
{
    if(*pl==NULL || e==NULL )
    {
        exit(EXIT_FAILURE);
    }

    struct ldc sent={-1 , *pl,NULL};
    struct ldc *p=&sent ;
    while(p->suiv!=sent.suiv)
    {
        if(p->suiv!=e)
        {
            p=p->suiv ;
        }
        else{
                p->suiv=p->suiv->suiv;
                p->suiv->suiv->prev=p;
                free(p->suiv);
                *pl=sent.suiv ;
                break ;

        }
    
    }

    if( p->suiv == sent.suiv)
    {
        printf("l'elemnt e n'est pas dans ldc \n");
        exit(EXIT_FAILURE);
    }
 

    
}

// Libère la mémoire occupée par chacun des éléments
// de la liste l.

void ldc_libere(struct ldc* l)
{

    struct ldc *p=l->suiv;
     

    while(p->suiv!=l){
        p = p->suiv;
        free(p->prev);
        

    }
    free(p);
    free(l);
 

}