package rational;
/* Vector.java
 *
 * Classe des vecteurs de rationnels
 *
 * Arnaud Ibakuyumcu
 */

public class Vector {

    ///////////////////////// ATTRIBUTS //////////////////////////////

    private Rational [] vect;
    private int taille = 0;

    //////////////////////// CONSTRUCTEUR ///////////////////////////

    /**
     * Constructeur :
     *
     * @param taille : Dimension du vecteur
     *
     * @return Vector : Un vecteur de taille Rational
     *
     */

    public Vector(int taille){

        vect = new Rational[taille];
        this.taille = taille;
    }

    ///////////////////////// SET & GET ///////////////////////////////

    /**
     * set get : Permet de manipuler les éléments du vecteurs
     *
     * @param int i : Indice de la composante impliquée dans le vecteur
     *
     * @param Rational r : Le rationnel à mettre ( cas du set )
     *
     * @throws IllegalArgumentException : Si l'indice est plus grand que la dimension du vecteur 
     *
     * @return Rational : Le rationnel visé ( cas du get )
     *
     */

    public void set(int i, Rational r){

        if (i < 0 || i >= taille)
            throw new IllegalArgumentException("L'indice n'est pas dans l'intervalle 0..taille-1");
        this.vect[i] = r;
    }

    public Rational get(int i){

        if (i < 0 || i >= taille)
            throw new IllegalArgumentException("L'indice n'est pas dans l'intervalle 0..taille-1"); 
        return this.vect[i];
    }

    ///////////////////////////// VECTEUR DYNAMIQUE /////////////////////////////

    /**
     * add : Permet de rajouter un rationnel en fin de vecteur, l'agrandissant.
     *
     * @param Rational r : Le rationnel à rajouter
     *
     */

    public void add(Rational r){

        Vector v =  new Vector(this.taille+1);
        for(int i=0; i<this.taille; i++)
            v.vect[i] = this.vect[i];
        v.vect[this.taille] = r;
        this.vect = v.vect;
        this.taille ++; 
    }

    ///////////////////////////// OPERATIONS ///////////////////////////////////

    /**
     * mult : Permet de multiplier un vecteur par un rationnel
     *
     * @param Rational r : Le scalaire multipliant le vecteur
     *
     */

    public void mult(Rational r){

        for(int i = 0; i<this.taille; i++)
            this.vect[i].mult(r);
    }

    /**
     * add : Permet d'additionner deux vecteurs de Rational
     *
     * @param Vector v : Le vecteur additionnant l'objet
     *
     * @throws IllegalArgumentException : Si les tailles des vecteurs sont différentes
     *
     */

    public void add(Vector v){

        if(v.taille != this.taille)
            throw new IllegalArgumentException("Les tailles des deux vecteurs a additionner sont différentes");
        for(int i=0; i<taille; i++)
            this.vect[i].add(v.vect[i]);
    }



    ///////////////////////////// AFFICHAGE ///////////////////////////////////

    /**
     * toString : Permet de transformer en String le vecteur de rationnels
     *
     * @return String : Le string du vecteur
     *
     */

    @Override
    public String toString(){

        String s = "(";
        for (int i=0; i<taille; i++){
            s += " " + this.get(i).toString() + " ";
        }
        s += ")";

        return s;
    }

    /**
     * getDimension : Permet de connaitre la taille du vecteur
     *
     * @return int : Taille du vecteur
     *
     */

    public int getDimension(){

        return this.taille;
    }

    /////////////////////////////// FIN ///////////////////////////////////////
}
