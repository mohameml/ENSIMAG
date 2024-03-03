package arithmetique.expBinaire;

import arithmetique.*;

//********************************************************************

public class ExpBinaireMult extends ExpBinaire{

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

//********************************************************************
