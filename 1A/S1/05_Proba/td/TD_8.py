
import random as rd

import sys 
def f():
    u=rd.uniform(0,1)
    v=rd.uniform(0,1)
    return u,v

def X_n():
    u,v=f()
    if u**2+v**2<=1:
        return 1
    else:
        return 0

n=10000

def Z_n(n):
    s=0
    for i in range(1,n+1):
        x=X_n()
        s+=x
    return (4/n)*s

print(Z_n(n))




