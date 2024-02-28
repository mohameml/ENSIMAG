#!/usr/bin/env python3


def pivote(tableau, indice_pivot):
    inferieur = []
    superieur = []
    for i in range(len(tableau)):
        if (i != indice_pivot):
            if (tableau[i] <= tableau[indice_pivot]):
                inferieur.append(tableau[i])
            else:
                superieur.append(tableau[i])
    return (inferieur, superieur)


tab1 = [3, 0, 10, 1, 6, 9, 5, 3, 9, 0, 5, 8, 9, 8, 4, 2, 0, 9, 6, 2]


print(pivote(tab1, 0))
