package arithmetique;
/*
 * ExpAbstraite.java
 *
 * Ibakuyumcu Arnaud
 */

import java.lang.Math;	

abstract public class ExpAbstraite {

    abstract public String toStringInfixe();
    abstract public double evaluer(Env env);
    abstract public ExpAbstraite derive(String var);
    public String toString(){

        return " Notation infixée : " + this.toStringInfixe();
    }

}
