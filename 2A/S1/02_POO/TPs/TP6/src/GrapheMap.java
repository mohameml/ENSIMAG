//////////////////////////////////
//                              //
// GrapheMap.java               //
//                              //
// Définition d'un graphe par   //
// la méthode des dictionnaires //
// Realise l'interface Graphe   //
//                              //
// Arnaud Ibakuyumcu            //
// Ensimag 2A                   //
//////////////////////////////////

import java.util.*;

public class GrapheMap implements Graphe{

    // Attributs

    private TreeMap<String, LinkedList<String>> graphe; // Tree pour le tri auto

    // Constructeur
    
    public GrapheMap(){
        graphe = new TreeMap<String, LinkedList<String>>();
    }

    // Méthodes à implémenter de l'interface Graphe

    @Override
    public void ajouteSommet(String label){
        if (!existe(label))
            graphe.put(label, new LinkedList<String>());
    }

    @Override
    public void ajouteArc(String labelDepart, String labelArrivee){
        if (!existe(labelDepart) || !existe(labelArrivee)){
            System.out.println("\n\n Le label de départ ou d'arrivée n'existe pas, l'arc n'est pas créé\n");
            return;
        }
        if (!existe(labelDepart,labelArrivee))
            graphe.get(labelDepart).add(labelArrivee);
    }

    @Override
    public boolean existeChemin(String labelDepart, String labelArrivee){
        if (!existe(labelDepart) || !existe(labelArrivee)){
            System.out.println("\n\n Le label de départ ou d'arrivée n'existe pas, l'arc n'est pas créé\n");
            return false;
        }
        // Initialisation du marquage des sommets
        HashMap<String, Boolean> marque = new HashMap<String, Boolean>();
        for (String s : graphe.keySet()){
            marque.put(s,false);
        }

        return existeCheminRec(labelDepart, labelArrivee, marque);
    }

    @Override
    public String toString(){
        String r = "\n";
        // Mise en place de l'itérateur
        Set<Map.Entry<String, LinkedList<String>>> couples = graphe.entrySet();
        Iterator<Map.Entry<String, LinkedList<String>>> itCouples = couples.iterator();
        // Affichage de chaque couple
        while (itCouples.hasNext()){
            Map.Entry<String, LinkedList<String>> couple = itCouples.next();
            r += "Sommet " + couple.getKey() + " de successeurs : " + couple.getValue().toString() + "\n";
        }
        return r;
    }

    // Méthodes privées
    private boolean existe(String label){
        return (graphe.get(label) != null);
    }

    private boolean existe(String label1, String label2){
        return (graphe.get(label1).contains(label2));
    }

    private boolean existeCheminRec(String labelDepart, String labelArrivee, HashMap<String, Boolean> marque){

        if (marque.get(labelDepart))
            return false;
        
        marque.put(labelDepart,true);

        boolean r = existe(labelDepart, labelArrivee);
        if (r)
            return true;

        for (String s : graphe.get(labelDepart)){
            r = r || existeCheminRec(s, labelArrivee, marque);
        }

        return r;
    }

}
