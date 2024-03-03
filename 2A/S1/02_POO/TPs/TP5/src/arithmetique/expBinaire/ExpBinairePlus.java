package arithmetique.expBinaire;

import arithmetique.*;

//**********************************************************

public class ExpBinairePlus extends ExpBinaire{

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

