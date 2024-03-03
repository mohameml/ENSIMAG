/* Rzgime.java
 *
 * Classe de regime des animaux 
 *
 * Arnaud Ibakuyumcu
 *
 */

public class Regime{

/////////////////////////////// ATTRIBUTS ///////////////////////////////

	private String nom;
        private int prix;

////////////////////////////// ACCESSEURS //////////////////////////////
	
	/**
	 * getPrix
	 *
	 * @return int : Le prix au kilo du régime
	 */

	public int getPrix(){
		return this.prix;
	}	

	/**
	 * toString
	 *
	 * @return String : Le nom du régime
	 */

	public String toString(){
		return this.nom;
	}

////////////////////////////////// CONSTRUCTEUR /////////////////////////

	/**
	 * Constructeur
	 *
	 * @param String nom : Nom du régime
	 * @param int prix : Prix au kilo du régime
	 */

	public Regime(String nom, int prix){
		this.nom = nom;
		this.prix = prix;
	}

/////////////////////////////////////////////////////////////////////////
}
