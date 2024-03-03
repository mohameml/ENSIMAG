package arithmetique.expUnaire;

import arithmetique.*;
import arithmetique.expBinaire.*;

//***********************************************************

public class ExpUnaireExp extends ExpUnaire{
    
    public ExpUnaireExp(ExpAbstraite op){
	super(op,"Exp");
    }

    @Override
    public double evaluer(Env env){
	return Math.exp(this.operande.evaluer(env));
    }

    @Override
    public ExpAbstraite derive(String var){
	return new ExpBinaireMult(
			operande.derive(var),
			new ExpUnaireExp(operande));
    }
}

// ***********************************************************

