package arithmetique;

//*****************************************************************************

public class Variable extends ExpAbstraite{

    String nom;

    public Variable(String nom){
        this.nom = nom;
    }

    @Override
    public double evaluer(Env env){
	double valeur = 0;
	try{	    
	    valeur = env.obtenirValeur(this.nom);
        }catch (IllegalArgumentException e) {
            System.out.println("\n\t== Exception ==\n\t== " + e + " ==\n\n");
            System.exit(0);
        }	

	return valeur;
    }

    @Override
    public ExpAbstraite derive(String var){
	    if (this.nom == var)
		    return new Constante(1);
	    else
		    return new Constante(0);
    }

    @Override
    public String toStringInfixe(){
        return nom;
    }
}

//*****************************************************************************
