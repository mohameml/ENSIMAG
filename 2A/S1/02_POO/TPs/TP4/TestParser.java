import java.util.*;

public class TestParser {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		System.out.println("\n\n ________________________ Calculette préfixée _______________________ \n");
		System.out.println("Veuillez saisir l'expression en notation préfixée. Utilisez des espaces entre chaque element ! : \n");
		System.out.println("--> Exemple :  + x * sin y 0.1 \n");
		System.out.println("C'est à vous !\n");

		String exprString = input.nextLine();

		System.out.println(" \n\n ************** Vous avez saisi : " + exprString + " *************** \n");
		Scanner sc = new Scanner(exprString);

		ExpAbstraite exp = parser(sc);
		if (sc.hasNext()) {
			// pas normal !
			throw new RuntimeException("Erreur. Expression mal formée");
		}

		System.out.println("\n\t" + exp.toString());

		while (true) {
			// création de l'environnement stockant les valeurs des variables
			System.out.println("\n-------------------------------------------------------------------------");
			System.out.println("\nVeuillez saisir les valeurs de toutes les variables (environnement)");
			System.out.println("\nFormat : <variable> <valeur> <variable> <valeur> sur une seule ligne.");
			System.out.println("\n--> Exemple x 2.5 y 3.1416 .... ");
			System.out.println("\nTapez exit pour sortir");
			System.out.println("C'est à vous !\n");
			input = new Scanner(System.in);
			String envString = input.nextLine();
			if (envString.equals("exit")) {
				System.out.println("\n\n*************** Bye bye ******************** \n");
				System.exit(0);
			}
			sc = new Scanner(envString);
			try {
				Env env = parserEnvironnement(sc);
				System.out.println("\nExpression    : " + exp.toStringInfixe());
				System.out.println("Environnement : " + env);
				double resultat = exp.evaluer(env);
				System.out.print("\n\t ****** Valeur de l'expression, compte tenu de l'environnement : ");
				System.out.println(resultat);
			} catch (Exception e) {
				System.out.println();
				System.out.println("Erreur detectee : " + e);
				System.out.println("Recommencez !");
			}
		}
	
	}

	static ExpAbstraite parser(Scanner sc) {
		if (!sc.hasNext()) {
			throw new RuntimeException("!!!!!!! Parsing impossible : il manque des operandes !");
		}

		String op = sc.next();

		switch (op) {
		case "+":
			ExpAbstraite opGauche = parser(sc);
			ExpAbstraite opDroite = parser(sc);
			return new ExpBinairePlus(opGauche, opDroite);

		case "*":
			return new ExpBinaireMult(parser(sc), parser(sc));

		case "-":
			return new ExpBinaireMoins(parser(sc), parser(sc));

		case "/":
			return new ExpBinaireDiv(parser(sc), parser(sc));

		case "sin":
			return new ExpUnaireSin(parser(sc));

		case "cos":
			return new ExpUnaireCos(parser(sc));

		case "tan":
			return new ExpUnaireTan(parser(sc));
		
		}

		try {
			double d = Double.parseDouble(op);
			return new Constante(d);
		} catch (NumberFormatException e) {
			System.out.println("\n\n==== EXCEPTION : PROBLEME DE FORMAT ===\n===" + e + "===");
			System.exit(0);
		}

		// est-ce une variable ?
		if (op.matches("[a-zA-Z]+?")) {
			// variable : uniquement des lettres !
			return new Variable(op);
		}

		throw new RuntimeException("parsing impossible : operateur '" + op
				+ "' non reconnu");
	}

	static Env parserEnvironnement(Scanner sc) {
		Env env = new Env();

		while (sc.hasNext()) {
			String varStr = sc.next();
			// est-ce une variable ?
			if (varStr.matches("[a-zA-Z]+?")) {
				String dblStr = sc.next();
				double d = Double.parseDouble(dblStr);
				env.associer(varStr, d);
			} else {
				throw new RuntimeException("Erreur. Nom de variable attendu");
			}
		}
		return env;
	}
}
