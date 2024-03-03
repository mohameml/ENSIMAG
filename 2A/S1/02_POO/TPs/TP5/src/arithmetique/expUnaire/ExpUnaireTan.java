package arithmetique.expUnaire;

import arithmetique.*;
import arithmetique.expBinaire.*;

//*********************************************************************

public class ExpUnaireTan extends ExpUnaire{

    public ExpUnaireTan(ExpAbstraite op){
        super(op,"Tan");
    }  

    @Override
    public double evaluer(Env env){
	return Math.tan(this.operande.evaluer(env));
    }

    @Override
    public ExpAbstraite derive(String var){
	    return new ExpBinaireMult(
			    operande.derive(var),
			    new ExpBinairePlus(
				    new Constante(1),
				    new ExpBinaireMult(
					    new ExpUnaireTan(operande),
					    new ExpUnaireTan(operande))));
    }
}

//*********************************************************************
