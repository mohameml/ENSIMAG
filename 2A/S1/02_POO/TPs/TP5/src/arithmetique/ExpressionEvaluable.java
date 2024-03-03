package arithmetique;
/* Implémentation de l'interface evaluable pour une expression arithmétique
 *
 * Ibakuyumcu Arnaud
 *
 */
import evaluable.*;

public class ExpressionEvaluable implements Evaluable{

	ExpAbstraite e;
	Env env;

	public ExpressionEvaluable(ExpAbstraite e, Env env){
		this.e = e;
		this.env = env;
	}

	@Override
	public double evaluer(){
		return (double)e.evaluer(env);
	}
}
