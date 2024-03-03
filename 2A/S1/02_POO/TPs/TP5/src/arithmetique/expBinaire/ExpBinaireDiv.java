package arithmetique.expBinaire;

import arithmetique.*;

//*******************************************************************************

public class ExpBinaireDiv extends ExpBinaire{

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

//*******************************************************************************
