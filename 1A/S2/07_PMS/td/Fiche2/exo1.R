# Feuille2 exo1
# question1

bruit <- c(54.8 ,55.4 ,57.7 ,59.6 ,60.1 ,61.2 ,62.0 ,63.1 ,63.5 ,64.2,65.2 ,65.4 ,65.9 ,66.0 ,67.6 ,68.1 ,69.5 ,70.6, 71.5 ,73.4)
n <-length(bruit)
plot(bruit)
summary(bruit)
sd(bruit)
coef <- (sqrt(n-1/n)*sd(bruit))/mean(bruit)
coef

# question 2


# hsito à classe de meme largeur 
lt <- sort(bruit)
n <- length(bruit)
k <- 5
diff <- lt[n]-lt[1]
a0 <- lt[1] -0.025*diff
a5 <- lt[n]+0.025*diff
h <- (a5 - a0)/k
bornes <- seq(a0, a5, (a5 - a0) / 5)
hist(lt,prob=T,col="blue",main="histo de bruit ")

# hisrto a classe de meme effetcife 
bornes <- c(a0, quantile(bruit,seq(1/5,4/5,1/5)),a5)
hist(bruit , prob=T,col="red")

# graphes des probabilites
plot(bruit,qnorm(seq(1,n)/n))
qqnorm(bruit)


# question 3
# question 3_a
# Estime mean et sd de loi Normale modilisant cet pb
m <- mean(bruit)
var <-(n-1/n) var(bruit)
m
var
sd <- sqrt(n-1/n)*sd(bruit)
# question 3_b
p1 <- 1-pnorm(70,mean=m,sd=sd)
p2 <- 1-pnorm(74,mean=m,sd=sd)
p1
p2
# Question 3_c
qnorm(0.9,m,sd=sd(bruit))
#question 4 
# Estimation de lambdea 
lambda <- 1/mean(bruit)
lambda
p1 <- 1-pexp(70,lambda)
p2 <- 1-pexp(74,lambda )
p1
p2
qexp(0.9,lambda)

#Question 5
p1 <- 1 - ecdf(bruit)(70)
p2 <- 1 - ecdf(bruit)(74)
p1
p2
quantile(bruit,0.9)
plot(ecdf(bruit))





















