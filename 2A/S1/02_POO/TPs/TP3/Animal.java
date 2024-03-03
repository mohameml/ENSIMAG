/* Animal.java
 *
 * Classes des Animaux
 *
 * Arnaud Ibakuyumcu
 */

// Classe principale Animal ( Pas de Public pour pouvoir en créer plusieurs dans 
// le même fichier )
//
// Voir la correction pour l'utilisation d'abstract de class ( permet de n'instancier que 
// des animaux spécifiques ( canard, lyon, vache ) et non générale ( animal )
// En effet, comment calculer le coût global si on ne sait pas quel est l'animal ?
// Il est alors important d'abstraire la classe animal
// On ne le fait pas ici pour que le test marche ! 

class Animal {

/////////////////////// ATTRIBUTS /////////////////////////////////

	private String nom;
	private int poids;
	public Regime regime;
	
////////////////////// ACCESSEURS ////////////////////////////////

	/**
	 * getPoids : Permet d'obtenir le poids d'un Animal
	 *
	 * @return int : Le poids de l'animal
	 */

	public int getPoids(){
		return this.poids;
	}

	/**
	 * getRegime
	 *
	 * @return Regime : Le régime de l'animal
	 */

	public Regime getRegime(){
		return this.regime;
	}

	/**
	 * toString
	 *
	 * @return String : Le nom de l'animal
	 */
	
	@Override
	public String toString(){
		return this.nom;
	}

	/**
	 * set : Permet de fournir le nom et le poids d'un Animal
	 *
	 * @param String nom : Le nom de l'animal
	 * @param int poids : Le poids de l'animal
	 * @param Regime regime : Le régime de l'animal
	 */

	public void set(String nom, int poids, Regime regime){
		this.nom = nom;
		this.poids = poids;
		this.regime = regime;
	}

//////////////////////// CONSTRUCTEUR /////////////////////////////////

	private final static Regime REGIME_UNKNOWN = new Regime("**",0); // static = partage
	/**
	 * Constructeur
	 *
	 * @param String nom : Le nom de l'animal
	 * @param int poids : Le poids de l'animal
	 * @param Regime regime : Le régime de l'animal
	 */

	public Animal(String nom, int poids, Regime regime){
		this.set(nom,poids,regime);
	}

	/**
	 * Cas d'un régime non connu
	 *
	 * @param String nom : Le nom de l'animal
	 * @param int poids : Le poids de l'animal
	 */

	public Animal(String nom, int poids){
		this(nom,poids,REGIME_UNKNOWN);
	}

//////////////////////// METHODES ///////////////////////////////////////:

	/** 
	 * crier
	 *
	 * @return Affiche le message " [nom] crie ... "
	 */

	public void crier(){
		System.out.println("\n\t " + this.toString() + " crie"); 
	}

	public String affiche(){
		return "\n " + this.toString() + " : un animal qui pèse " + this.poids + " kg";
	}

	// Fonction de calcul de coût qui dépend de la sous-classe de l'animal !
	public int coutNourriture(){
		return 0;
	}
}

//*********************************************************************************************
// Classes spécifiques

class Canard extends Animal {

//////////////////////// ATTRIBUT ///////////////////////////

	private String couleurPlume;

/////////////////////// CONSTRUCTEUR ///////////////////////

	/**
	 * Constructeur
	 *
	 * @param String nom : Nom de l'animal de type Canard
	 * @param int poids : Poids du canard
	 * @param String plume : Couleur des plumes
	 */

	private final static Regime REGIME_CANARD = new Regime("Graines",10);

	public Canard(String nom, int poids, String plume){
		super(nom,poids,REGIME_CANARD); // super = classe au dessus ( Animal )
		this.couleurPlume = plume;
	}

/////////////////////// ACCESSEURS //////////////////////////

	/** 
	 * getPlume
	 *
	 * @return String : La couleur des plumes du canards
	 */

	public String getPlume(){
		return this.couleurPlume;
	}

	/**
	 * toString
	 *
	 * @return String : Le nom du canard
	 */

	@Override
	public String toString(){
		return super.toString() + ", le canard aux belles plumes " + this.getPlume();
	}

////////////////////// METHODES ///////////////////////////

	/**
	 * crier
	 *
	 * @return Fais crier l'animal
	 */

	@Override
	public void crier(){

		super.crier();
		System.out.println("\t : Il cancanne ");
	}	

	/**
	 * coutNourriture
	 *
	 * @return int : Le cout de la nourriture pour un canard
	 */

	@Override
	public int coutNourriture() {
		return regime.getPrix();
	}

}

// ***********************************************************************************

class Vache extends Animal {

//////////////////////// ATTRIBUT ///////////////////////////

	private int nombreTache;

/////////////////////// CONSTRUCTEUR ///////////////////////

	/**
	 * Constructeur
	 *
	 * @param String nom : Nom de l'animal de type Vache
	 * @param int poids : Poids de la vache
	 * @param int nombreTache : Nombre de taches
	 */

	private final static Regime REGIME_VACHE = new Regime("Paille",5);

	public Vache(String nom, int poids, int nombreTache){
		super(nom,poids,REGIME_VACHE); // super = classe au dessus ( Animal )
		this.nombreTache = nombreTache;
	}

/////////////////////// ACCESSEURS //////////////////////////

	/** 
	 * getTache
	 *
	 * @return int : Le nombre de tache de la vache
	 */

	public int getTache(){
		return this.nombreTache;
	}

	/**
	 * toString
	 *
	 * @return String : Le nom de la vache
	 */

	@Override
	public String toString(){
		return super.toString() + ", la vache " + 
			(nombreTache == 0 ? "sans tâche" : "aux " + this.getTache() + " tâches");
	}

////////////////////// METHODES ///////////////////////////

	/**
	 * crier
	 *
	 * @return Fais crier l'animal
	 */

	@Override
	public void crier(){

		super.crier();
		System.out.println("\t : Elle meugle ");
	}

	/**
	 * coutNourriture
	 *
	 * @return int : Le cout de la nourriture pour une vache
	 */

	@Override
	public int coutNourriture() {
		return this.getTache() * regime.getPrix();
	}
	
}

// ***********************************************************************************

class Lion extends Animal {

//////////////////////// ATTRIBUT ///////////////////////////

	private int age;

/////////////////////// CONSTRUCTEUR ///////////////////////

	/**
	 * Constructeur
	 *
	 * @param String nom : Nom de l'animal de type Lion
	 * @param int poids : Poids du lion
	 * @param int age : Âge du lion
	 */

	private final static Regime REGIME_LION = new Regime("Viande", 20);

	public Lion(String nom, int poids, int age){
		super(nom,poids,REGIME_LION); // super = classe au dessus ( Animal )
		this.age = age;
	}

/////////////////////// ACCESSEURS //////////////////////////

	/** 
	 * getTache
	 *
	 * @return int : L'age du lion
	 */

	public int getAge(){
		return this.age;
	}

	/**
	 * toString
	 *
	 * @return String : Le nom du lyon
	 */

	@Override
	public String toString(){
		return super.toString() + ", le lion de " + this.getAge() + " ans";
	}

////////////////////// METHODES ///////////////////////////

	/**
	 * crier
	 *
	 * @return Fais crier l'animal
	 */

	@Override
	public void crier(){

		super.crier();
		System.out.println("\t : Il rugit ");
	}	

	/**
	 * coutNourriture
	 *
	 * @return int : Le cout de la nourriture pour un lion
	 */

	@Override
	public int coutNourriture() {
		return (this.getAge() / 2) * regime.getPrix();
	}
}
