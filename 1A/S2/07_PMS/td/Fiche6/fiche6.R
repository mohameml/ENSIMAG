# Principes et Méthodes Statistiques
# Fiche 6

# Création des données et représentation du nuage de points
vitesse<-c(5,10,15,20,25,30,35,40)
freinage<-c(3.42,5.96,31.14,41.76,74.54,94.92,133.78,169.16)
n<-length(vitesse)
plot(vitesse,freinage, xlim=c(-1,45), ylim=c(-40,180))
abline(v=0)
abline(h=0)

# Régression avec le modèle initial
regvf<-lm(freinage~vitesse)
summary(regvf)
abline(regvf, col="blue")

# Régression avec le modèle simplifié
regvf3<-lm(freinage~vitesse-1)
# lm(freinage~vitesse+0) donne exactement la même chose !
summary(regvf3)
abline(regvf3, col="red")

# Estimation de beta
betachap<-regvf3$coefficient
# ou coef(regvf3)
betachap

# Intervalle de confiance pour beta
confint(regvf3)

# Estimation de sigma^2
sigma2chap <- sum((freinage-betachap*vitesse)^2)/(n-1)
sigma2chap

# Intervalle de confiance pour sigma^2
(n-1)*sigma2chap/qchisq(1-alpha/2, n-1)
(n-1)*sigma2chap/qchisq(1-(1-alpha/2), n-1)

# Erreur quadratique moyenne minimale
(n-1)*sigma2chap/n

# Coefficient de corrélation linéaire empirique
sum(vitesse*freinage)/sqrt(sum(vitesse^2)*sum(freinage^2))
