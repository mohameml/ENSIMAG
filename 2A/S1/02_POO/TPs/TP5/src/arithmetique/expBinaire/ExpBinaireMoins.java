package arithmetique.expBinaire;

import arithmetique.*;

//**********************************************************

public class ExpBinaireMoins extends ExpBinaire{

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
