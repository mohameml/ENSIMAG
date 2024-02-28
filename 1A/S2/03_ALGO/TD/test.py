#!/usr/bin/env python3
import time
import matplotlib.pyplot as plt

" ce programme sert a visualiser la compleexite d'un Alog "


def somme(n):
    s = 0
    for i in range(n):
        s += 1

    return s


" la complexite de sommen(n) est O(n)"
" on veut demonter sa par une representation graphique de sommen(n)=f(n)"
time_som = []
valeures = [i for i in range(500, 2*10**4, 500)]

for n in valeures:
    t1 = time()
    somme(n)
    t2 = time()
    time_som.append(t2-t1)
plt.plot(valeures, time_som)
plt.show()
