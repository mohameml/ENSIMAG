package tests;
/* Permet de tester l'interface Evaluable
 *
 * Ibakuyumcu Arnaud
 */

import java.util.*;
import arithmetique.*;
import arithmetique.expBinaire.*;
import arithmetique.expUnaire.*;
import rational.*;
import evaluable.*;

public class TestInterfaceEvaluable {
	public static void main(String[] args) {
		ArrayList<Evaluable> list = new ArrayList<Evaluable>();

		// création de l'environnement stockant les valeurs des variables
		Env env = new Env();
		env.associer("y", 2);
		env.associer("x", 1);
		env.associer("a", 9);
		env.associer("b", 3);

		// on ajoute quelques expressions...
		ExpAbstraite exp;
		
		exp = new ExpBinaireMult(new Variable("y"), new Constante(3));
		list.add(new ExpressionEvaluable(exp, env));

		exp = new ExpBinaireMult(new ExpBinairePlus(new Variable("x"),
				new Variable("x")), new Constante(5));
		list.add(new ExpressionEvaluable(exp, env));

		exp = new ExpBinaireMult(new Constante(-3.5), new ExpUnaireSin(
				new ExpBinairePlus(new Variable("a"), new Variable("b"))));
		list.add(new ExpressionEvaluable(exp, env));

		// on ajoute quelques rationnels...
		list.add(new RationalEvaluable(17, 2));
		list.add(new RationalEvaluable(9));

		
		// affichage
		System.out.println("Ensemble des objets evaluables:");
		int i = 1;
		for (Evaluable e : list) {
			System.out.println(i++ + ". " + e 
					+ "\t --> evaluation: " + e.evaluer());
		}
		System.out.println("");

		// recherche du minimum 
		Evaluable min = rechercherMin(list);
		if (min != null) {
			System.out.println("L'objet d'evaluation minimale est: " + min);
			System.out.println("Sa valeur double est: " + min.evaluer());
		}
	}
	
	private static Evaluable rechercherMin(ArrayList<Evaluable> list) {
		if (list.isEmpty()) {
			return null;
		}
		
		Evaluable min = list.get(0);
		for (Evaluable e : list) {
			if (e.evaluer() < min.evaluer()) {
				min = e;
			}
		}
		return min;
	}

}
