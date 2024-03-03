/* TestZoo.java
 *
 * Classe de test de la classe Animal, zoo 
 *
 * Arnaud Ibakuyumcu
 *
 */

public class TestZoo{

	public static void main(String [] args){

//********** ANIMAL 1

		System.out.println("\n ______________________ TEST DE LA CLASSE ANIMAL _____________________ \n\n");

		// CREATION ET AFFICHAGE D'UN ANIMAL

		System.out.println("\n ********************** Création, Affichage et crie ****************** ");
		// Création
		Animal arnaud = new Animal("Arnaud", 50);
		// Affichage
		System.out.println("\n " + arnaud.affiche());
		// Crie
		arnaud.crier();

//********* ZOO 1

		System.out.println("\n ______________________ TEST DE LA CLASSE ZOO ________________________ \n\n");

		// CREATION ET AFFICHAGE D'UN ZOO
		
		System.out.println("\n ********************* Création, Affichage et crie ******************* ");
		// Création du zoo et d'autres animaux
		Zoo ensimag = new Zoo("Ensimag");
		Animal kwan = new Animal("Kwan", 30);
		Animal yaya = new Animal("Yaya", 60);
		Animal pierre = new Animal("Pierre", 10);
		Animal alex = new Animal("Alex", 70);
		Animal robin = new Animal("Robin", 160);
		// Ajout des animaux au zoo
		ensimag.ajouteAnimal(arnaud);
		ensimag.ajouteAnimal(kwan);
		ensimag.ajouteAnimal(yaya);
		ensimag.ajouteAnimal(pierre);
		ensimag.ajouteAnimal(alex);
		ensimag.ajouteAnimal(robin);
		// Affichage du zoo
		System.out.println("\n\n " + ensimag.toString());
		// Crie de tous les animaux
		ensimag.crier();
		
//********** ANIMAL 2

		System.out.println("\n ____________________ TESTS DES SOUS CLASSES __________________ \n\n");

		// CREATION ET AFFICHAGE D'ANIMAUX SPECIFIQUES

		System.out.println("\n ********************* Création, Affichage et crie ****************** ");
		// Création d'animaux spécifiques
		Canard robert = new Canard("Robert", 50, "bleus");
		Vache jean = new Vache("Jean", 30, 30);
		Vache maite = new Vache("Maite", 300, 20);
		Lion sam = new Lion("Sam", 100, 22);
		// Affichage
		System.out.println("\n" + robert.affiche());
		System.out.println("\n" + maite.affiche());
		System.out.println("\n" + sam.affiche());
		// Crie
		robert.crier();
		maite.crier();
		sam.crier();

		System.out.println("\n");

//*********** ZOO 2 + REGIME	

		System.out.println("\n _______________ TESTS DU ZOO FINAL AVEC REGIME __________________ \n\n");

		// CREATION DU ZOO 
		Zoo ensi = new Zoo("Ensi");
		// Ajout des animaux
		ensi.ajouteAnimal(robert);
		ensi.ajouteAnimal(jean);
		ensi.ajouteAnimal(maite);
		ensi.ajouteAnimal(sam);
		// Affichage du zoo
		System.out.println("\n\n " + ensi.toString());

		// Régime de chaque animaux :
		System.out.println("\n\n ***************** REGIME DE CHAQUE ANIMAL *************** \n");
		System.out.println("\n" + robert.toString() + " mange 1 kg de "
					+ robert.getRegime().toString()); 
		System.out.println("\n" + jean.toString() + " mange " + jean.getTache() + " kg de "
					+ jean.getRegime().toString()); 
		System.out.println("\n" + maite.toString() + " mange " + maite.getTache() + " kg de "
					+ maite.getRegime().toString()); 
		System.out.println("\n" + sam.toString() + " mange " + (sam.getAge() / 2) + " kg de "
					+ sam.getRegime().toString());

		// Cout total
		System.out.println("\n\n ****** Cout total pour le zoo : " + ensi.cout() + " euros. \n");	
		

	}
}
