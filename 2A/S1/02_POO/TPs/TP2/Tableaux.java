
public class Tableaux {

	public static void main(String [] args) {

	// tableau 1D, type primitif
		int [] tab;        	// ici t n'est pas initialise 
		tab = new int[5];  	// allocation dynamique. 
		                    //  => indices de 0 a tab.length - 1, ici 4
							//  => valeurs initialisees a 0
		tab[0] = 2;         // acces via l'operateur []

	// tableau 1D d'objets
		Entier [] tabE;
		tabE = new Entier[5];		// ne contient que des références null
		for (int i = 0; i < tabE.length; i++)
			tabE[i] = new Entier(2 * i);	// alloc objet par objet
		
		// autre parcours, de type "for each" 
		// (pour appliquer un traitement à *tous* les éléments)
		for (Entier e : tabE) {
			System.out.println(e.toString());
		}
		
		
	// tableau 2D
		int [][] tab2D;
		tab2D = new int[5][];	// tab de 5 références null
		for (int i = 0; i < tab2D.length; i++) {
			// allocation case par case. Dimenstion par forcément identiques
			tab2D[i] = new int[i + 1];
		}		
	}
}



class Entier {
	private int valeur;
	
	public Entier (int valeur) {
		this.valeur = valeur;
	}

	@Override
	public String toString() {
		return "(" + valeur + ")";
	}
}

