/*
 * Env.java
 *
 * Ibakuyumcu Arnaud
 */

import java.util.*; // Pour les tables de Hachages

public class Env{
	// Attribut : Dictionnaire
	Map<String, Double> dico = new HashMap<String, Double>();
	// Méthodes :
	
	public void associer(String nom, double valeur){
	    this.dico.put(nom,valeur);
	}

	public double obtenirValeur(String nom){ // Gestion du cas où nom n'existe pas !
	    if (this.dico.get(nom) == null)
		throw new IllegalArgumentException("La variable n'est associé à aucune valeur");
	    
	    return this.dico.get(nom); 
	}

	public String toString(){
	    return this.dico.toString();
	}
}
