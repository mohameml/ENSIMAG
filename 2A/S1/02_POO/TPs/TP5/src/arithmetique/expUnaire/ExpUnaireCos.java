package arithmetique.expUnaire;

import arithmetique.*;
import arithmetique.expBinaire.*;

//**********************************************************

public class ExpUnaireCos extends ExpUnaire{

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

