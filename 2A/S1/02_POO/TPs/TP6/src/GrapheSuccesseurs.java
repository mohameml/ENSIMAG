//////////////////////////////////
//                              //
// GrapheSuccesseurs.java       //
//                              //
// Définition d'un graphe par   //
// la méthode des successeurs   //
// Realise l'interface Graphe   //
//                              //
// Arnaud Ibakuyumcu            //
// Ensimag 2A                   //
//////////////////////////////////

import java.util.*;

public class GrapheSuccesseurs implements Graphe{

    // Attributs

    private LinkedList<Sommet> somm;

    // Constructeur
    public GrapheSuccesseurs(){
        somm = new LinkedList<Sommet>();
    }

    // Méthodes à implémenter de l'interface Graphe
    
    @Override
    public void ajouteSommet(String label){
        if (!existe(label))
            somm.add(new Sommet(label));
    }

    @Override
    public void ajouteArc(String labelDepart, String labelArrivee){
        if (!existe(labelDepart) || !existe(labelArrivee)){
            System.out.println("\n\n Le label de départ ou d'arrivée n'existe pas, l'arc n'est pas créé\n");
            return;
        }
        // On ajoute aux successeurs du sommet de départ le sommet d'arrivé
        // On interdit les graphes multiples
        if (!existe(labelDepart,labelArrivee))
            findSommet(labelDepart).addSucc(findSommet(labelArrivee));
    }

    @Override
    public boolean existeChemin(String labelDepart, String labelArrivee){
        if (!existe(labelDepart) || !existe(labelArrivee)){
            System.out.println("\n\n Le label de départ ou d'arrivée n'existe pas\n");
            return false;
        }
        // Initialisation des sommets ( tous non marqué )
        for (Sommet s : somm)
            s.marque(false);
        
        return existeCheminRec(findSommet(labelDepart), findSommet(labelArrivee));        
    }

    @Override
    public String toString(){
        String r = "\n";
        for (Sommet s : somm)
            r += s.toString() + "\n";
        return r;
    }


    // Méthodes privée

    // Le sommet label existe t-il ?
    private boolean existe(String label){
        for (Sommet s : somm){
            if (s.getLabel().equals(label))
                return true;
        }
        return false;
    }

    // L'arc label1 -> label2 existe t-il ?
    private boolean existe(String label1, String label2){
        return findSommet(label1).existeSucc(findSommet(label2));
    }

    // Programmation récursive de recherche de chemin
    private boolean existeCheminRec(Sommet sDepart, Sommet sArrivee){
        
        // Si on est déjà passé c'est qu'il n'existe pas de chemin
        if (sDepart.estMarque())
            return false;
        // Sinon on dit qu'on traite ce point ( on le marque donc )
        sDepart.marque(true);

        // Si le chemin est un arc du sommet de départ au sommet d'arrivé c'est bon
        boolean r = sDepart.existeSucc(sArrivee);
        if (r)
            return true;

        // Sinon on va voir parmi les successeurs
        for (Sommet s : sDepart.getSucc()){
            r = r || existeCheminRec(s, sArrivee);
        }

        return r;
    }

    // Renvoie une référence du sommet label
    private Sommet findSommet(String label){
        for (Sommet s : somm){
            if (s.getLabel().equals(label))
                return s;
        }
        return null; // Cas qui n'arrive jamais
    }    
}
