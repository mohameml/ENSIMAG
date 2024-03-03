package tests;
/* Pour le test des expressions dérivées
 *
 * Ibakuyumcu Arnaud
 */

import arithmetique.*;
import arithmetique.expUnaire.*;
import arithmetique.expBinaire.*;


public class TestDerive {
	public static void main(String[] args) {
		ExpAbstraite exp;

		// Test de l'expression (x-1)*x + y/x + sin(x-y)
		System.out.println("\n\n ******************* Test de la dérivée ******************* \n\n");

		exp = new ExpBinairePlus(
				new ExpBinaireMult(
					new ExpBinaireMoins(
						new Variable("x"),
						new Constante(1)),
					new Variable("x")),
				new ExpBinairePlus(
					new ExpBinaireDiv(
						new Variable("y"),
						new Variable("x")),
					new ExpUnaireSin(
						new ExpBinaireMoins(
							new Variable("x"),
							new Variable("y")))));

		System.out.println("------> Expression : " + exp.toStringInfixe());

		// Dérivation
		ExpAbstraite expD;
		expD = exp.derive("x");

		System.out.println("\n\n ------> Expression dérivée par rapport à x : " + expD.toStringInfixe());

		// Application
		Env env = new Env();
		env.associer("x",3);
		env.associer("y",2);
		System.out.println("\n\t Avec l'environnement : " + env);
		System.out.println("\n\n On obtient les résultats suivants : \n");

		System.out.println("------> Expression : " + exp.evaluer(env));
		System.out.println("------> Expression dérivée : " + expD.evaluer(env) + "\n\n*****************************");

	}
}
