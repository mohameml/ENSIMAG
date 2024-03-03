///////////////////////
//                   //
// Sommet.java       //
//                   //
// Définition d'un   //
// sommet de graphe  //
//                   //
// Arnaud Ibakuyumcu //
// Ensimag 2A        //
///////////////////////

import java.util.*;

public class Sommet{

    // Attributs

    private String label;
    private boolean mark;
    private LinkedList<Sommet> succ;

    // Constructeur

    /** 
     * Constructeur
     *
     * @param String label du sommet
     *
     */
    public Sommet(String label){
        this.label = label;
        mark = false;
        succ = new LinkedList<Sommet>();
    }

    // Méthodes
    // Get & Set
    
    /**
     * getLabel
     *
     * @return String : Le label du sommet
     *
     */
    public String getLabel(){
        return label;
    }

    /**
     * getSucc
     *
     * @return LinkedList<Sommet> : La liste des successeurs du sommet
     *
     */
    public LinkedList<Sommet> getSucc(){
        return succ;
    }

    /**
     * addSucc : Ajoute un successeur s au sommet
     *
     * @param Sommet s : Le sommet a ajouter comme successeur
     *
     */
    public void addSucc (Sommet s){
        succ.add(s);
    }

    /**
     * marque : Marque le sommet comme visité ou non
     *
     * @param boolean b : Comment marquer le sommet
     */
    public void marque(boolean b){
        mark = b;
    }

    /**
     * estMarque : Retourne le marquage du sommet
     *
     * @return boolean : True s'il est marqué
     *
     */
    public boolean estMarque(){
        return mark;
    }

    // Autres

    /**
     * existeSucc : Le sommet s existe t-il dans les successeurs du sommet
     *
     * @param Sommet s : Le sommet à verifier l'existence
     *
     * @return Boolean : True s'il existe
     *
     */
    public boolean existeSucc(Sommet s){
        return succ.contains(s);
    }

    /**
     * toString()
     *
     * @return String : Une définition du sommet
     *
     */
    @Override
    public String toString(){
        String r = "Sommet " + label + " de successeurs : ";
        for (Sommet s : succ){
            r += "| " + s.getLabel() + " |";
        }
        return r;
    }


}
