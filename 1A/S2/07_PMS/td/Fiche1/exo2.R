# EXO2 fiche 1
# Question 1
# histpgramme à classe de meme largeur 
l <- c(0.516 , 0.887, 0.783, 0.613, 0.697, 0.459, 0.724, 0.755, 0.867, 0.893, 0.835, 0.718 ,0.851, 0.386, 0.855)
lt <- sort(l)
n <- length(l)
k <- round(1+log2(n))
diff <- lt[n]-lt[1]
a0 <- lt[1] -0.025*diff
ak <- lt[n]+0.025*diff
h <- (ak - a0)/k
hist(lt,prob=T,breaks=seq(a0,ak,h),col="blue",main="histo de tremb ",ylim=c(0,5))


# histogramme à classe de meme effectif
bornes <- c(a0,quantile(lt,seq(1,k-1)/k),ak)
bornes
hist(lt,prob=T,breaks=bornes,col="red",main="histo de tremb ",ylim=c(0,5))


# reprsentaion de deux histo dans le meme graphe
par=(mfcol=c(1,2))
hist(lt,prob=T,breaks=seq(a0,ak,h),col="blue",main="histo de tremb ",ylim=c(0,5))
hist(lt,prob=T,breaks=bornes,col="red",main="histo de tremb ",ylim=c(0,5))

# Question2
# densite de loi uniforme
plot(dunif,xlim=c(-5,5))

# graphe de probabilites de loi puissance Pu(t,c)
plot(lt,log(seq(1,n)/n),col="green")
