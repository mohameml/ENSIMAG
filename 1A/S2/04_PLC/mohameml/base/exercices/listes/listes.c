#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

/**
 * @brief Structure de données décrivant un élément d'une liste.
 *
 */
struct cellule
{
    uint32_t val;           /**< La valeur d'une cellule est un entier */
    struct cellule* suiv;   /**< Pointeur vers la cellule suivant dans la liste */
};

/**
 * @brief Affiche sur la sortie standard les valeurs des cellules d'une liste.
 *
 * @param l la liste à afficher
 */
static void afficher(struct cellule* l)
{
    /* A implémenter! */
    if(l==NULL)
       exit(EXIT_FAILURE);
    else 
      printf("%d--> ", l->val);
    
    struct cellule *suiv = l->suiv ;

    while( suiv != NULL){
        printf("%d--> ", suiv->val );
        suiv =suiv->suiv ; 
    }
    printf("FIN\n");

}

/**
 * @brief Insère une nouvelle cellule en tête d'une liste.
 *
 * @param pl l'adresse de la tête de la liste à étendre
 * @param v la valeur de la nouvelle cellule à créer et insérer
 */
static void inserer_tete(struct cellule** pl, uint32_t v)
{
    /* A implémenter! */
    struct cellule *tete = malloc(sizeof(struct cellule ));
    tete->val = v ;
    tete->suiv= (*pl) ; 
    *pl = tete ;

}

/**
 * @brief Insère une nouvelle cellule en dernière position d'une liste.
 *
 * @param pl l'adresse de la tête de la liste à étendre
 * @param v la valeur de la nouvelle cellule à créer et insérer
 */
static void inserer_queue(struct cellule** pl, uint32_t v)
{
    /* A implémenter! */
    if(*pl==NULL)
       inserer_tete( pl,  v);
    
    else{
        struct cellule sent ={2 , *pl}; 
        struct cellule *suiv = &sent   ;


       while( suiv->suiv != NULL)
       {
        suiv =suiv->suiv ; 
       }  
     suiv->suiv= malloc(sizeof(struct cellule ));
     suiv->suiv->val=v;
     suiv->suiv->suiv=NULL ;
     *pl=sent.suiv ;


    }

}


/**
 * @brief Supprime la première occurrence d'une valeur dans une liste.
 *
 * @param pl l'adresse de la tête de la liste sur laquelle appliquer la suppression
 * @param v la valeur que l'on souhaite supprimer de la liste
 */
static void supprimer_premiere_occurrence(struct cellule** pl, uint32_t v)
{
    /* A implémenter! */

    struct  cellule sent = {2 , *pl};
    struct  cellule *p = &sent ;
    
    
    while(p->suiv!= NULL && p->suiv->val!=v )
        {
           p = p->suiv ;
        }

        
        if(p->suiv !=NULL)
        {
            struct cellule *style = p->suiv ;
            p->suiv=style->suiv ;
           free(style);

        }
        *pl=sent.suiv;
        

    

}

/**
 * @brief Point d'entrée du programme.
 *
 * @return int 0 (EXIT_SUCCESS) si tout s'est bien passé
 */
int main(void)
{
    struct cellule* liste = NULL;
    for (uint32_t i = 6; i < 10; i++) {
        inserer_queue(&liste, i);
        afficher(liste);
    }
    for (uint32_t i = 5; i > 0; i--) {
        inserer_tete(&liste, i);
        afficher(liste);
    }

    /*
        Initialisation du générateur de nombres aléatoires
        (nécessaire pour que rand() retourne des valeurs différentes à chaque
        exécution du programme).
    */
    srand(time(NULL));

    while (liste != NULL) {
        supprimer_premiere_occurrence(&liste, rand() % 10);
        afficher(liste);
    }
    return EXIT_SUCCESS;
}
