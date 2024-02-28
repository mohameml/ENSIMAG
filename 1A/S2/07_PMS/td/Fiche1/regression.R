# dans ce fichier on implente qq methode de regression linéaire 
x<-c(.516 ,0.887 ,0.783 ,0.613 ,0.697 ,0.459 ,0.724 ,0.755
  ,0.867 ,0.893, 0.835 ,0.718 ,0.851 ,0.386, 0.855)
n<-length(x)
# on desine le graphe de proba de loi de puissannce (dans TD1)
abs <- log(sort(x))
ord<-log(seq(1:n)/n)
plot(abs,ord)

# on remarque que les pts dans le graphe sont quasiment alingés

# regression linéare 
reg <- lm(ord~abs)
summary(reg)
# pramétre theta
b <- reg$coefficients[1]
theta <- exp(-b/reg$coefficients[2])
theta
# paramétre c de la loi de puissance 
c <- reg$coefficients[2]
c
# on desine la dte de regrresion 
plot(sort(x),fitted.values(reg))
lines(sort(x),fitted.values(reg))
