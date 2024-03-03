import java.util.LinkedList;

/* Zoo.java
 *
 * Classe Zoo 
 *
 * Arnaud Ibakuyumcu
 *
 */

class Zoo {

//////////////////// ATTRIBUTS ////////////////////////////////
	private String nom;
	private LinkedList<Animal> animaux;
	
/////////////////// CONSTRUCTEUR /////////////////////////////

	public Zoo(String nom) {
		this.nom = nom;
		animaux = new LinkedList<Animal>();
	}

/////////////////// ACCESSEURS /////////////////////////////////
	
	public int getNbAnimaux() {
		return animaux.size();
	}
	
	@Override
	public String toString() {
		return "Le zoo " + nom + " contient: \n" + animaux; 
	}

////////////////// METHODES //////////////////////////////////////

	public void ajouteAnimal(Animal animal) {
		animaux.add(animal);
	}

	public void crier() {
		System.out.println("\n\n *** 1, 2, 3 crions: ");
		for (Animal a : animaux) {
			a.crier();
			System.out.println("\n");
		}
	}

	public int cout(){
		int r = 0;
		for (Animal a : animaux){
			r += a.coutNourriture();
		}
		return r;
	}
	
	
}
