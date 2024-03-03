/*
 * ExpAbstraite.java
 *
 * Ibakuyumcu Arnaud
 */

import java.lang.Math;	

abstract class ExpAbstraite {

    abstract public String toStringInfixe();
    abstract public double evaluer(Env env);
    abstract public ExpAbstraite derive(String var);
    public String toString(){

        return " Notation infixée : " + this.toStringInfixe();
    }

}

//**********************************************************

abstract class ExpBinaire extends ExpAbstraite{
 
    ExpAbstraite opGauche;
    ExpAbstraite opDroite;
    String operateur;

    public ExpBinaire(ExpAbstraite opG, ExpAbstraite opD, String operateur){
        this.opGauche = opG;
        this.opDroite = opD;
        this.operateur = operateur;
    }

    @Override
    abstract public double evaluer(Env env);
    @Override
    abstract public ExpAbstraite derive(String var);

    @Override
    public String toStringInfixe(){
        
        String s = "(";
        s += this.opGauche.toStringInfixe();
        s += this.operateur;
        s += this.opDroite.toStringInfixe();
        s += ")";

        return s;
    }
}

   
//**********************************************************

abstract class ExpUnaire extends ExpAbstraite{

    ExpAbstraite operande;
    String operateur;

    public ExpUnaire(ExpAbstraite op, String operateur){
        this.operande = op;
        this.operateur = operateur;
    }

    @Override
    abstract public double evaluer(Env env);
    @Override
    abstract public ExpAbstraite derive(String var);

    @Override
    public String toStringInfixe(){
        String s = this.operateur;
        s += "(";
        s += this.operande.toStringInfixe();
        s += ")";

        return s;
    }
}

//**********************************************************

class Constante extends ExpAbstraite{

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

class Variable extends ExpAbstraite{

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

//**********************************************************

class ExpBinairePlus extends ExpBinaire{

    public ExpBinairePlus(ExpAbstraite opG, ExpAbstraite opD){
        super(opG,opD,"+");
    }

    @Override
    public double evaluer(Env env){
	return opGauche.evaluer(env) + opDroite.evaluer(env);
    }

    @Override
    public ExpAbstraite derive(String var){
	    return new ExpBinairePlus(opGauche.derive(var),opDroite.derive(var));
    }
}

//**********************************************************

class ExpBinaireMult extends ExpBinaire{

    public ExpBinaireMult(ExpAbstraite opG, ExpAbstraite opD){
        super(opG,opD,"*");
    }  

    @Override
    public double evaluer(Env env){
	return opGauche.evaluer(env) * opDroite.evaluer(env);
    }

    @Override
    public ExpAbstraite derive(String var){
	    return new ExpBinairePlus(
			    new ExpBinaireMult(opGauche.derive(var),opDroite),
			    new ExpBinaireMult(opGauche,opDroite.derive(var)));
    }

}

//**********************************************************

class ExpBinaireMoins extends ExpBinaire{

    public ExpBinaireMoins(ExpAbstraite opG, ExpAbstraite opD){
	super(opG,opD,"-");
    }

    @Override
    public double evaluer(Env env){
	return opGauche.evaluer(env) - opDroite.evaluer(env);
    }

    @Override
    public ExpAbstraite derive(String var){
	    return new ExpBinaireMoins(opGauche.derive(var),opDroite.derive(var));
    }
}

//************************************************************

class ExpBinaireDiv extends ExpBinaire{

    public ExpBinaireDiv(ExpAbstraite opG, ExpAbstraite opD){
	super(opG,opD,"/");
    }

    @Override
    public double evaluer(Env env){
	return opGauche.evaluer(env) / opDroite.evaluer(env);
    }

    @Override
    public ExpAbstraite derive(String var){
	    return new ExpBinaireDiv(
			    new ExpBinaireMoins(
				    new ExpBinaireMult(opGauche.derive(var),opDroite),
				    new ExpBinaireMult(opGauche,opDroite.derive(var))),
			    new ExpBinaireMult(
				    opDroite,
				    opDroite));
    }
}


//************************************************************

class ExpUnaireSin extends ExpUnaire{

    public ExpUnaireSin(ExpAbstraite op){
        super(op,"Sin");
    }  

    @Override
    public double evaluer(Env env){
	return Math.sin(this.operande.evaluer(env));
    }

    @Override
    public ExpAbstraite derive(String var){
	    return new ExpBinaireMult(
			    operande.derive(var),
			    new ExpUnaireCos(operande));
    }
}

//**********************************************************

class ExpUnaireCos extends ExpUnaire{

    public ExpUnaireCos(ExpAbstraite op){
        super(op,"Cos");
    }

     @Override
    public double evaluer(Env env){
	return Math.cos(this.operande.evaluer(env));
    }

    @Override
    public ExpAbstraite derive(String var){
	    return new ExpBinaireMoins(
			    new Constante(0),
			    new ExpBinaireMult(
				    operande.derive(var),
				    new ExpUnaireCos(operande)));
    }

}

//**********************************************************

class ExpUnaireTan extends ExpUnaire{

    public ExpUnaireTan(ExpAbstraite op){
        super(op,"Tan");
    }  

    @Override
    public double evaluer(Env env){
	return Math.tan(this.operande.evaluer(env));
    }

    @Override
    public ExpAbstraite derive(String var){
	    return new ExpBinairePlus(
			    new Constante(1),
			    new ExpBinaireMult(
				    operande.derive(var),
				    new ExpBinaireMult(
					    new ExpUnaireTan(operande),
					    new ExpUnaireTan(operande))));
    }
}

