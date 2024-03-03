package arithmetique.expUnaire;

import arithmetique.*;
import arithmetique.expBinaire.*;

//**********************************************************

public class ExpUnaireLn extends ExpUnaire{
    
    public ExpUnaireLn(ExpAbstraite op){
	super(op,"Ln");
    }

    @Override
    public double evaluer(Env env){
	return Math.log(this.operande.evaluer(env));
    }

    @Override
    public ExpAbstraite derive(String var){
	return new ExpBinaireDiv(
			operande.derive(var),
			operande);
    }
}

//**********************************************************
