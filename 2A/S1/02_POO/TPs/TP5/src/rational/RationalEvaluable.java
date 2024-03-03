package rational;
/* Implémente l'interface Evaluable pour les rationals
 *
 * Ibakuyumcu Arnaud
 *
 */
import evaluable.*;

public class RationalEvaluable implements Evaluable{
	Rational r;

	public RationalEvaluable(int n){
		this.r = new Rational(n);
	}
	public RationalEvaluable(int n, int d){
		this.r = new Rational(n,d);
	}
	
	@Override
	public double evaluer(){
		return (double)r.getNum()/(double)r.getDenom();
	}
}
