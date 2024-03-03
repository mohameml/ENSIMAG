package arithmetique.expBinaire;

import arithmetique.*;

//**********************************************************

abstract public class ExpBinaire extends ExpAbstraite{
 
    ExpAbstraite opGauche;
    ExpAbstraite opDroite;
    String operateur;

    public ExpBinaire(ExpAbstraite opG, ExpAbstraite opD, String operateur){
        this.opGauche = opG;
        this.opDroite = opD;
        this.operateur = operateur;
    }

    @Override
    abstract public double evaluer(Env env);
    @Override
    abstract public ExpAbstraite derive(String var);

    @Override
    public String toStringInfixe(){
        
        String s = "(";
        s += this.opGauche.toStringInfixe();
        s += this.operateur;
        s += this.opDroite.toStringInfixe();
        s += ")";

        return s;
    }
}

//************************************************************
