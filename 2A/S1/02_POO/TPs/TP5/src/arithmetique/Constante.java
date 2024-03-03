package arithmetique;

//**********************************************************

public class Constante extends ExpAbstraite{

    double valeur;

    public Constante(double valeur){
        this.valeur = valeur;
    }

    @Override
    public double evaluer(Env env){
	    return this.valeur;
    }

    @Override
    public ExpAbstraite derive(String var){
	    return new Constante(0);
    }

    @Override
    public String toStringInfixe(){
        return Double.toString(this.valeur);
    }
}

//**********************************************************

