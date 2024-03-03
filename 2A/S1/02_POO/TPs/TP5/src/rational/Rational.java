package rational;
/* Rational.java
 *
 * Classe des rationnels
 *
 * Arnaud Ibakuyumcu
 */

public class Rational {

    //////////////////////// VARIABLES /////////////////////////////::

    // Ils sont privée : on ne peut faire objet.num et objet.denom que dans ce fichier.
    // Dans un autre fichier on utilise les Set/Get
    private int num;
    private int denom;

    //////////////////////////// SET & GET ///////////////////////////

    /** 
     * setNum : Set de la variable numérateur, simplificationd du rationnel
     *
     * @param int num : le numérateur entier
     *
     */

    public void setNum( int num ){

        this.num = num;
        this.simplifie();
    }

    /** 
     * setDenom : Set de la variable dénominateur, simplification du rationnel
     *
     * @param int denom : le dénominateur entier
     *
     * @throws IllegalArgumentException : Si le dénominateur vaut 0
     *
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
     * @return int : Le numérateur entier
     *
     */

    public int getNum(){

        return num;
    }

    /**
     * getDenom : Get de la variable dénominateur
     *
     * @return int : Le dénominateur entier
     *
     */

    public int getDenom(){

        return denom;
    }


    ///////////////////////////////////// CONSTRUCTEURS ///////////////////////////////////////

    /**
     * Constructeur de l'objet : 
     *
     * @param int num : Le numérateur entier
     * @param int denom : Le dénominateur entier
     *
     * @return Rational : Le rationnel num/denom
     *
     */

    public Rational(int num, int denom){

        this.num = num;
        try{
            this.setDenom(denom);
        } catch (IllegalArgumentException e) {
            System.out.println("\n\t Le dénominateur doit être différent de 0. Le programme va quitter ! ");
            System.exit(0);
        }
    }

    /**
     * Constructeur de l'objet entier :
     *
     * @param int num : L'entier à allouer
     *
     * @return Rationnal : Le rationnel num/1
     *
     */

    public Rational(int num){

        this(num,1);
    } 

    /**
     * Coonstructeur de l'objet copie :
     *
     * @param Rational r : Le rationnel à copier
     *
     * @return Rational : Le rationnel valant r
     *
     */

    public Rational(Rational r){
        this(r.num, r.denom);
    }

    /////////////////////////////////////// OPERATIONS ////////////////////////////////

    /** 
     * mult : Multiplie deux rationnels et stock le résultat dans l'objet
     *
     * @param Rational b : Le rationnel à multiplier
     *
     */

    public void mult(Rational b){ // On est pas obligé d'utiliser les get ici, ni les this ( pas de confusion possible )
                                  // On utilise les set car ils permettent de simplifier en direct        
        setNum(num * b.num);
        setDenom(denom * b.denom);
    }

    /** 
     * add : Additionne deux rationnels et stock le résultat dans l'objet
     *
     * @param Rational b : Le rationnel à additionner
     *
     */

    public void add(Rational b){

        setNum(num*b.denom + b.num*denom);
        setDenom(denom * b.denom);
    }

    /** 
     * mult : Multiplie deux rationnels et retourne le résultat
     *
     * @param Rational a : Un des rationnels à multiplier
     * @param Rational b : L'autre rationnel à multiplier
     *
     * @return Rational : Le résultat de a*b
     *
     */

    public static Rational mult(Rational a, Rational b){ // Static : méthode de classe !

        Rational res = new Rational(a.num, a.denom);
        res.mult(b);

        return res;
    }


    /////////////////////////////////////// AFFICHAGE /////////////////////////////////

    /**  
     * toString : Convertit en string le rationnel
     *
     * @param Rational r : Le rationnel  à convertir 
     *
     * @return String : Le string convertit
     *
     */

    @Override // Permet la ré-écriture de la fonction toString qui existe déjà par défaut pour toute classe ! 
    public String toString(){

        return new String(this.getNum() + (this.getDenom() != 1 ? "/" + this.getDenom() : "")); // Pas obligé d'utiliser les get
    }


    /**
     * affiche : Affiche le rationnel
     *
     * @param Rational r : Le rationnel à afficher ! 
     *
     */

    public void affiche() {

        System.out.println(" \n Maintenant le rationnel est : " + this.toString() + "\n" );
    }

    //////////////////////// FONCTIONS INTERMEDIAIRES ////////////////////////////////

    // En private car on ne les utilise qu'ici

    // Retourne le pgcd de deux entiers
    private static int pgcd(int a, int b){

        if (b==0)
            return a;
        return pgcd(b, a % b);
    }

    // Simplifie un rationnel
    private void simplifie(){

        int pgcd = Rational.pgcd(num,denom);
        num /= pgcd;
        denom /= pgcd;
        if (denom < 0){
            num = -num;
            denom = -denom;
        }
    }

    ///////////////////////// FIN ///////////////////////////////
}
