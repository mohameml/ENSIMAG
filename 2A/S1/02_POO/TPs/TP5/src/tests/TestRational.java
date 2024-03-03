package tests;
/* TestRational.java
 *
 * Test des différentes méthodes de 
 * la classe Rational des rationnels
 *
 * Arnaud Ibakuyumcu
 *
 */

import rational.*;

public class TestRational { 

    public static void main (String[] args) {

        System.out.println(" \n______________ TEST DE LA CLASSE RATIONAL ________________ \n\n");

        // CREATION ET AFFICHAGE D'UN RATIONAL
        System.out.println("\n ******************** Création et affichage ****************** \n");
        // Constante de test ( modifiable ICI )
        final int NUM = 3;
        final int DENOM = 2; // Différent de 0

        System.out.println(" \n Le numérateur est : " + NUM);        
        System.out.println(" \n Le dénominateur est : " + DENOM);

        // Création de l'objet Rational
        Rational r = new Rational(NUM,DENOM);

        // Affichage du rationnel
        r.affiche();

        // TEST DE L'EXCEPTION / DENOMINATEUR = 0
        System.out.println(" \n ******************** Exception dénominateur = 0 ******************* \n");
        System.out.println(" \n Modifions le dénominateur en 0 ... \n");

        try{
            r.setDenom(0);
        }catch (IllegalArgumentException e) {
            System.out.println("\n\t== Exception non traitée ici, mais ça devrait quitter le programme ==\n\t== " + e + " ==");
            //System.exit(0);
        }

        r.affiche();

        //TEST DE L'ADDITION / MULTIPLICATION
        System.out.println("\n ********************* Multiplication et Addition ********************* \n");

        // Création d'un autre rationnel
        Rational p = new Rational(4*NUM, DENOM+3);

        // Multiplication 
        System.out.println("\n Multiplication entre " + r.toString() + " et " + p.toString());
        r.mult(p);
        r.affiche();

        // Addition
        System.out.println("\n Addition entre " + r.toString() + " et " + p.toString());
        r.add(p);
        r.affiche();

        // TEST DE LA SIMPLIFICATION : ( Les rationnels doivent toujours être simplifié : invariant de classe )
        // TEST DE LA METHODE DE MULTIPLICATION EN SURCHARGE
        System.out.println("\n ********************** Multiplication surcharge ********************* \n");
        System.out.println("\n Multiplication entre " + r.toString() + " et " + p.toString() + " sans modifier l'objet" );

        // Multiplication par méthode de classe ( Pas besoin d'objet )
        p = Rational.mult(r,p);
        p.affiche();

        // Affichage de r
        System.out.println("\n Le premier rationnel est toujours : " + r.toString());

        // FIN
        System.out.println("\n\n ******************* FIN DU TEST ******************* \n");

    }
}
