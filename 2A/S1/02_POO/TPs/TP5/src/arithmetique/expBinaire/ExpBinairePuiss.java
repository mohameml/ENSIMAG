package arithmetique.expBinaire;

import arithmetique.*;

//************************************************************

public class ExpBinairePuiss extends ExpBinaire{

    public ExpBinairePuiss(ExpAbstraite opG, ExpAbstraite opD){
	super(opG,opD,"^");
    }

    @Override
    public double evaluer(Env env){
	return Math.pow(opGauche.evaluer(env),opDroite.evaluer(env));
    }

    @Override
    public ExpAbstraite derive(String var){
	ExpAbstraite buf = new ExpUnaireExp(new ExpBinaireMult(opDroite, new ExpUnaireLn(opGauche)));
	return buf.derive(var);
    }
}


//************************************************************

