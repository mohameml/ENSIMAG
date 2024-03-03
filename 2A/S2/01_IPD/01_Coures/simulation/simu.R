#!/usr/local/bin/Rscript

######################################
# Arnaud Ibakuyumcu
# ENSIMAG IF 2A
# 4 Mars 2016
# Version 1.0
######################################
# Simulation d'un mouvement brownien
# standard W par la méthode du 
# pont brownien entre [0,T]
#
# Simulation du max d'un MBS
# entre [0,T]
######################################

# simuPontBr : Fonction intermediaire de simulation
#	       d'un pont brownien (u,v) decalé 
#	       Necessaire pour simuMBS
# param u      extremite gauche du pont
# param v      extremite droite du pont
# param a      valeur de Wu
# param b      valeur de Wv
# param t      temps de la simulation dans [u,v]
# 
# Retourne une simulation de 
# Wt | Wu=a, Wv=b
simuPontBr <- function(u,v,a,b,t){
	mu <- a + ((t-u)/(v-u))*(b-a)
	var <- ((v-t)*(t-u))/(v-u)
	return(rnorm(1,mu,var))
}

# simuMBS : Fonction de simulation d'un MBS
#
# param tf   le temps final
# param ytf  la valeur du MBS à tf (defaut N(0,tf))
# param h    la precision recherchée
# param col  la couleur du graphique (defaut "blue")
# param type le type de graphique "p" = point,
#		                  "l" = ligne,
#				  "b" = les deux (defaut "b")
# param pch  le symbole pour les points (defaut 16)
# param titl titre du graphique et de la sortie svg (defaut "simuMBS")
#
# return   ensemble de réalisation du MBS à différents temps
#
# details  Dessine un graphique du MBS entre [0,tf]
#
simuMBS <- function(tf,h,ytf=rnorm(1,0,tf),col="blue",type="b",pch=16,titl="simuMBS"){

	# recMBS : Fonction de recursivite utilisé dans
	#	   simuMBS
	#	   Realise un point au milieu de [u,v]
	#	   Puis fais le coté droite, puis gauche
	#          par récursion.
	#
	# param u      temps droite
	# param v      temps gauche
	# param a      valeur de Wu
	# param b      valeur de Wv
	# param ig     L'indice gauche
	# param id     L'indice droit
	#
	# s'arrete lorsque id -ig > 1
	recMBS <- function(u,v,a,b,ig,id,env=parent.frame()){
		# S'il reste un point à réaliser entre les deux indices
	if ((id-ig) > 1){
			#Calcul du milieu
			real <- simuPontBr(u,v,a,b,(u+v)/2)
			y <- get("y",envir=env)
			i <- (id+ig)/2
			y[i] <- real			
			#Traitement à droite
			recMBS((u+v)/2,v,real,b,i,id)
			#Traitement à gauche
			recMBS(u,(u+v)/2,a,real,ig,i)
			assign("y",y,envir=env);
		}
	}


	# 1) Recherche du nombre de subdivision
	#    de [0,tf] de la forme [t_i,t_{i+1}]
	#    de longueur < h

	n <- 0
	while(tf/(2^n) > h){
		n <- n+1
	}

	# 2) Creation du vecteur des simulations
	y <- c(0) #y[1] = W0 = 0 pour un MBS

	y[(2^n)+1] <- ytf

	# 3) Recursion de simulation des autres points
	# Calcul de T/2 puis etc...
	recMBS(0,tf,0,ytf,1,((2^n)+1))

	# 4) Dessin de la simulation
	plot(seq(0,tf,by=(tf/(2^n))),y,col=col,type=type,
	     pch=pch,main=titl,xlab="Temps",ylab="Valeur du MBS")
	legend("topright",legend=paste("Max :",max(y)),pch=15,col="black")

	return(y)
}

# simuMaxMBS : Fonction de simulation du maximum d'un pont brownien
# 
# param tf   : Le temps final
# param ytf  : La valeur du MBS en tf (defaut N(0,tf))
# param n    : Le nombre de simulation (defaut 1)
# param col  : Couleur du graphique (defaut "blue")
# param pch  : Type du symbole des points (defaut 16)
# param titl : Titre du graphique (defaut "simuMaxMBS")
#
# return Le vecteur des n réalisations
#
# details Dessine le nuage de point des simulations
simuMaxMBS <- function(tf,ytf=rnorm(1,0,tf),n=1,col="blue",pch=16,titl="simuMaxMBS"){
		# Simulation par inversion 
		u <- runif(n) 
		y <- (1/2)*(ytf + sqrt(ytf^2 - 2*tf*log(u)))

		# Nuage de point
		ylab <- paste("Max du MBS pour W",tf,sep="")
		ylab <- paste(ylab, " = ", ytf,sep="")
		plot(y,col=col,pch=pch,main=titl,xlab="Index",ylab=ylab)
		# Moyenne 
		mu <- mean(y)
		sigma <- var(y)
		abline(h=mu,col=col,lty=6,lwd=2)
		legend("topright",legend=c(paste("Moyenne",mu),paste("Variance",sigma))
		       ,pch=15,col=col)

		return(list(real=y,mean=mu,var=sigma))
}
