#Partie1
#question1

x <-c(73.1 ,72.4 ,76.3 ,77.1 ,83.6 ,75.5 ,78.3 ,80.7 ,77.2 ,77.8,71.3 ,73.7 ,82.1 ,80.3 ,69.8 ,74.1 ,77.6 ,80.9 ,68.7 ,75.2)
n<-length(x)
plot(sort(x)[1:n-1],qnorm(seq(1,n-1)/n))
m <- mean(x)
ecart_type <- sd(x)
m
ecart_type

# on fait un test d'hypothése sur m H0="m>=m0" et H1="m<m0" avec m0=80
m0 <- 80
alpha <- 0.05 
t <-(sqrt(n)/sd(x))*(mean(x)-m0)
t

# onleui compare avec 
q <- qt(alpha,n-1)
q
t.test(x,alternative ="less",mu=80)
# calcul de p-valeur 
p <- pt((sqrt(n)/sd(x))*(mean(x)-m0),n-1)
p
# un interval de cofiance de seuil alpha 
# l'un de borne est -inf et l'autre borne2
borne2 <- mean(x)+(sd(x)/sqrt(n))*(-qt(alpha,n-1))
borne2
