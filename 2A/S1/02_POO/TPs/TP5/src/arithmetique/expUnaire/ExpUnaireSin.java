package arithmetique.expUnaire;

import arithmetique.*;
import arithmetique.expBinaire.*;

//********************************************************************

public class ExpUnaireSin extends ExpUnaire{

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

//********************************************************************
