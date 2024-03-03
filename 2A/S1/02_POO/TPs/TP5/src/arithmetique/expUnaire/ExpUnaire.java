package arithmetique.expUnaire;

import arithmetique.*;

//**********************************************************

abstract class ExpUnaire extends ExpAbstraite{

    ExpAbstraite operande;
    String operateur;

    public ExpUnaire(ExpAbstraite op, String operateur){
        this.operande = op;
        this.operateur = operateur;
    }

    @Override
    abstract public double evaluer(Env env);
    @Override
    abstract public ExpAbstraite derive(String var);

    @Override
    public String toStringInfixe(){
        String s = this.operateur;
        s += "(";
        s += this.operande.toStringInfixe();
        s += ")";

        return s;
    }
}

//**********************************************************

