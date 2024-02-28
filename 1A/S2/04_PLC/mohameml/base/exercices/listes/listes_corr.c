#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <assert.h>

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
    while (l != NULL) {
        printf("%i -> ", l->val);
        l = l->suiv;
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
    /*
        Rappel : une liste est définie comme un pointeur vers la première
        cellule.  Comme cette fonction modifie la liste (la première cellule),
        la fonction appelante doit passer l'adresse de la liste pour pouvoir
        observer les changements (cf fiche passage de paramètres du kit de
        démarrage). Ainsi pl contient l'adresse de la liste et *pl désigne la
        liste (cad l'adresse de la première cellule).
    */

    /*
        On alloue une nouvelle cellule, qui sera la tête de la nouvelle liste.
        L'opérateur sizeof calcule le nombre d'octet à allouer pour le type
        voulu.
    */
    struct cellule* liste = malloc(sizeof(struct cellule));
    /*Programmation défensive : on vérification que malloc s'est bien passé*/
    assert(liste != NULL);
    /* On fixe les valeurs de cette cellule. */
    liste->val = v;
    liste->suiv = *pl;
    /* On fait pointer l'argument pl vers la nouvelle liste */
    *pl = liste;
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
    /*
        Cette fonction prend en argument un pointeur sur la liste, car cette
        dernière change dans le cas de l'insertion de la première cellule.

        On place une sentinelle de manière à gérer à l'identique tous les cas
        incluant le cas liste vide. Le champ suiv de notre sentinelle sera la
        liste que l'on voudra retourner.
    */
    struct cellule sent = { -1, *pl };
    struct cellule* queue = &sent;
    /* On parcourt la liste jusqu'à la dernière cellule */
    while (queue->suiv != NULL) {
        queue = queue->suiv;
    }
    /* Allocation et insertion de la cellule */
    queue->suiv = malloc(sizeof(struct cellule));
    assert(queue->suiv != NULL);
    queue->suiv->val = v;
    queue->suiv->suiv = NULL;
    /* On fait pointer l'argument pl vers la nouvelle liste */
    *pl = sent.suiv;
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
    /*
        Cette fonction prend en argument un pointeur sur la liste, car cette
        dernière change lorsqu'on supprime la première cellule.
    */
    struct cellule sent = { -1, *pl };
    struct cellule* p = &sent;
    /*
        En C, les conditions sont évaluées séquentiellement. L'expression à
        droite d'une condition logique && n'est évaluée que si l'expression à
        gauche est vraie.
    */
    while (p->suiv != NULL && p->suiv->val != v) {
        p = p->suiv;
    }

    /* Cas occurence trouvée */
    if (p->suiv != NULL) {
        /*
            On rechaine les 2 cellules de la liste entourant l'occurrence et on
            libère la cellule trouvée.
        */
        struct cellule* style = p->suiv;
        p->suiv = style->suiv;
        free(style);
    }
    *pl = sent.suiv;
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
