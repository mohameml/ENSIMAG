/* Rational.java
 *
 * Classe des rationnels
 *
 * Arnaud Ibakuyumcu
 */

public class Rational {

//////////////////////// VARIABLES /////////////////////////////::

    /**
     * Classe des rationnels : 
     *      Variables : Entiers num et denom en privée
     *      Méthodes : test (permet le test de la classe)
     */

    // Ils sont privée : on ne peut faire objet.num et objet.denom que dans ce fichier.
    // Dans un autre fichier on utilise les Set/Get
    private int num;
    private int denom;

//////////////////////////// SET & GET ///////////////////////////

    /** 
     * setNum : Set de la variable numérateur, simplificationd du rationnel
     *
     * @param num : le numérateur entier
     */

    public void setNum( int num ){
        this.num = num;
        this.simplifie();
    }

    /** 
     * setDenom : Set de la variable dénominateur, simplification du rationnel
     *
     * @param denom : le dénominateur entier
     *
     * @throws IllegalArgumentException : Si le dénominateur vaut 0
     */

    public void setDenom( int denom ){
        if (denom == 0)
            throw new IllegalArgumentException("Le dénominateur ne peut pas valoir 0");
        this.denom = denom;
        this.simplifie();
    }
    
    /**
     * getNum : Get de la variable numérateur
     *
     * @return le numérateur entier
     */

    public int getNum(){
        return num;
    }

     /**
     * getDenom : Get de la variable dénominateur
     *
     * @return le dénominateur entier
     */

    public int getDenom(){
        return denom;
    }


///////////////////////////////////// CONSTRUCTEUR ///////////////////////////////////////

    /**
     * Constructeur de l'objet : 
     *
     * @param num : le numérateur entier
     * @param denom : le dénominateur entier
     *
     * @return : L'objet Rational num/denom
     *
     */

    public Rational(int num, int denom){
        this.num = num;
        try{
            this.setDenom(denom);
        } catch (IllegalArgumentException e) {
            System.out.println("\n\tException traitée ici, le programme quitte");
            System.exit(0);
        }
    }

/////////////////////////////////////// OPERATIONS ////////////////////////////////

    /** 
     * mult : Multiplie deux rationnels et stock le résultat dans l'objet
     *
     * @param b : rationnel à multiplier
     */

    public void mult(Rational b){ // On est pas obligé d'utiliser les get ici, ni les this ( pas de confusion possible )
                                  // On utilise les set car ils permettent de simplifier en direct        
        setNum(num * b.num);
        setDenom(denom * b.denom);
    }

    /** 
     * add : Additionne deux rationnels et stock le résultat dans l'objet
     *
     * @param b : rationnel à additionner
     */

    public void add(Rational b){
        
        setNum(num*b.denom + b.num*denom);
        setDenom(denom * b.denom);
    }

    /** 
     * mult : Multiplie deux rationnels et retourne le résultat
     *
     * @param a : rationnel à multiplier
     * @param b : rationnel à multiplier
     *
     * @return Le résultat de a*b
     */

    public Rational mult(Rational a, Rational b){

        Rational res = new Rational(a.num, a.denom);
        res.mult(b);

        return res;
    }


/////////////////////////////////////// AFFICHAGE /////////////////////////////////

    /**  
     * Convertit en string le rationnel
     *
     * @param r : Rational
     *
     * @return Le string convertit
     */

    @Override
    public String toString() {

        return new String(this.getNum() + "/" + this.getDenom()); // Pas obligé d'utiliser les get
    }


    /**
     * Affiche le rationnel
     *
     * @param r : Rational
     */

    public void affiche() {
        System.out.println(" \n Maintenant le rationnel est : " + this.toString() + "\n" );
    }

//////////////////////// FONCTIONS INTERMEDIAIRES ////////////////////////////////

    // En private car on ne les utilise qu'ici

    // Retourne le pgcd de deux entiers
    private int pgcd(int a, int b){
        if (b==0)
            return a;
        return pgcd(b, a % b);
    }

    // Simplifie un rationnel
    private void simplifie(){
        int pgcd = pgcd(num,denom);
        num = num / pgcd;
        denom = denom / pgcd;
    }

///////////////////////// FIN ///////////////////////////////
}
