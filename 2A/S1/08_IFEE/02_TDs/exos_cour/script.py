#!/usr/bin/env python3



def VAN(I0 , K , tab ):

    van = -I0 

    for i in range(len(tab)) :
        e = tab[i]
        van += e/((1+K/100)**(i+1))

    return van


print(VAN(1100 , 15 , [-20,570,770,390,300])) # res = 192.03 k euro     