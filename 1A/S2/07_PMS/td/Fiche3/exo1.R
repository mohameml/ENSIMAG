# exercice1 de fiche 3
# question 1
x <-c(75 ,265 ,225 ,402 ,35 ,105 ,411 ,346 ,159 ,229,62, 256 ,431 ,177
      ,56 ,144 ,354, 178 , 386 ,294)
n <- length(x)
# on trace le histogramme des ce données de classe de méme largeur
xt <- sort(x)
k <-round( 1+log2(n))
a0 <- xt[1]-0.025*(xt[20]-xt[1])
ak <- xt[20]+0.025*(xt[20]-xt[1])
h <- (ak-a0)/k
bornes <- seq(a0,ak,h)
hist(x,prob=T,breaks =bornes )
# on trace le histogramme de ces données de classe de méme effectif
bornes1 <- c(a0,quantile(x,seq(1,k-1)/k),ak)
hist(x,prob=T,breaks=bornes1)

# on dessine mnt le graphe de proba pour valider le modéle 
plot(sort(x),seq(1,n)/n)

# le graphe de proba de loi exp
plot(sort(x)[1:n-1],log(1-seq(1,n-1)/n))

# le graphe de proba de loi normale
plot(sort(x),qnorm(seq(1,n)/n))
