public class TestEval { 
	public static void main(String[] args) {
		// création de l'environnement
		Env env = new Env();
		env.associer("y", 2);
		env.associer("x", 1);
		env.associer("a", 9);
		env.associer("b", 3);
		System.out.println("\n\n Environnement actuel : " + env);
  
		ExpAbstraite exp ;
		// teste l'expression préfixée *  y  3
		exp = new ExpBinaireMult(new Variable("y"), new Constante(3)) ;
		System.out.println("\n\t **** " + exp.toStringInfixe());
		System.out.print( "\nValeur de l'expression, compte tenu des valeurs des variables : ");
		System.out.println( exp.evaluer(env) );
		
		
		// teste l'expression préfixée * + x x 5
		exp = new ExpBinaireMult(
		                new ExpBinairePlus(
		                                   new Variable("x"), 
		                                   new Variable("x")
		                ),
		                new Constante(5)
		);
		System.out.println("\n\t ****" + exp.toStringInfixe());
		System.out.print( "\nValeur de l'expression, compte tenu des valeurs des variables : ");
		System.out.println( exp.evaluer(env) );		
  
		// teste l'expression préfixée * -3.5 sin + a b
		exp = new ExpBinaireMult(
		            new Constante(-3.5),
		            new ExpUnaireSin(
		                    new ExpBinairePlus(
		                            new Variable("a"), 
		                            new Variable("b") 
		                    )
		            )
		);
		System.out.println("\n\t ****" + exp.toString());
		System.out.print( "\nValeur de l'expression, compte tenu des valeurs des variables : ");
		System.out.println( exp.evaluer(env) );

		// Cas où la variable n'existe pas !
		System.out.println("\n\n \t **** Cas où la variable n'existe pas : ");
		exp = new ExpBinairePlus(new Constante(4), new Variable("z"));
		System.out.println("\n\t ****" + exp.toString());
		System.out.print( "\nValeur de l'expression, compte tenu des valeurs des variables : ");
		System.out.println( exp.evaluer(env) );

	}
}
