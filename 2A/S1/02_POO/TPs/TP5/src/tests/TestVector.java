package tests;
/* TestVector.java
 *
 * Classe de test de la classe Vector 
 *
 * Arnaud Ibakuyumcu
 *
 */

import rational.*;

public class TestVector{

    public static void main(String [] args){

        System.out.println(" \n______________ TEST DE LA CLASSE VECTOR ________________ \n\n");

        // CREATION ET AFFICHAGE D'UN VECTEUR DE RATIONAL

        System.out.println("\n ******************** Création et affichage ****************** \n");
        // Constante de test ( modifiable ICI )
        final int TAILLE = 4;
        final int CST = 3;

        // Création du vecteur
        Vector v = new Vector(TAILLE);
        for (int i = 0; i<TAILLE; i++)
            v.set(i, new Rational(3*i+1-CST, i*CST+3));

        // Affichage du vecteur
        System.out.println("\n Le vecteur vaut : " + v.toString());

        // TEST DU CAS DEMANDE DANS LE SUJET
        System.out.println("\n ******************* Test du cas demandé dans le TP ******************\n");

        // Création de rationnels
        Rational r1 = new Rational(2,3);
        Rational r2 = new Rational(3,2);

        // Modification de la première composante
        v.set(0,r1);
        System.out.println("\n Le vecteur vaut maintenant (set de la première composante) : " + v.toString() + "\n");

        // r1 <- r1*r2
        r1.mult(r2);

        System.out.println("\n Le vecteur vaut après multiplication du rationnel utilisé pour la 1ère composante : " + v.toString() + "\n");
        System.out.println("\n\t On remarque qu'on a modifié un rationnel mais la première composante du vecteur s'est aussi modifiée ");
        System.out.println("\n\t Ceci est normal car notre vecteur est un tableau de pointeur vers les rationnels ");
        System.out.println("\n\t Pour éviter ceci, il suffit de différencier les rationnels du vecteur et ceux qu'on utilise pour le remplir"); 	

        // TEST DE L'EXCEPTION D'INDICE

        System.out.println("\n ********************** Test set/get avec un indice trop élevé ******************** \n");

        try{
            v.set(TAILLE,r1);
        }catch (IllegalArgumentException e) {
            System.out.println("\n\t == Exception non traitée ici, mais le programme devrait quitter == \n\t == " + e + " == ");
        }

        // TEST DE LA MULTIPLICATION ET ADDITION

        System.out.println("\n ************************* Test des multiplications et additions ********************* \n");

        r2.setNum(4); // Attention, r1 pointe maintenant exactement sur le même Rational que v[0], on utilise r2
        r2.setDenom(3);

        System.out.println("\n On multiplie le vecteur " + v.toString() + " par le rationnel " + r2.toString() + " \n ");

        // Multiplication
        v.mult(r2);

        System.out.println("\n On obtient le vecteur : " + v.toString());

        // Création d'un nouveau vecteur
        Vector v2 = new Vector(v.getDimension());
        for (int i = 0; i<TAILLE; i++)
            v2.set(i, new Rational(2*i+1-CST, i*CST+4));

        System.out.println("\n\n Maintenant, additionnons le au vecteur : " + v2.toString());

        // Addition
        v.add(v2);

        System.out.println("\n On obtient le vecteur : " + v.toString());

        // AJOUT D'UN RATIONNEL EN FIN DE VECTEUR

        System.out.println("\n\n Ajoutons le rationnel " + r2.toString() + " au vecteur précédent");
        v.add(r2);

        System.out.println("\n On obtient le vecteur : " + v.toString());

        // FIN DU TEST
        System.out.println("\n\n __________________________ FIN DU TEST _____________________________\n ");
    }
}
