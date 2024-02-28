#!/usr/bin/env python3

from math import pi, cos, sin
from random import randint, uniform
from collections import deque
import os

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, autre):
        return Point(self.x+autre.x, self.y+autre.y)

    def __mul__(self, scalaire):
        return Point(self.x*scalaire, self.y*scalaire)


def fleurs():
    nom_image = "fleurs.png"
    tronc = (Point(400, 580), 250, -pi/2)
    with open(nom_image, 'w') as fichier_svg:
        print("<svg width='800' height='600'>", file=fichier_svg)
        print("<g stroke-width='0.5%' stroke='black'>", file=fichier_svg)
        branches = parcours_largeur(tronc,
                                    lambda b: filter(
                                        lambda b: b[1] >= 3,
                                        (sous_branche(b) for _ in range(randint(2,5)))
                                        )
                                    )
        premieres_branches = take(branches, 4000)
        for index, branche in enumerate(premieres_branches):
            couleur = 255 * (index/4000)
            print(f"<g stroke='rgb({couleur}, 0, 0)'>", file=fichier_svg)
            depart, longueur, angle = branche
            fin = depart + Point(cos(angle), sin(angle)) * longueur
            print(f"<line x1='{depart.x}' y1='{depart.y}' x2='{fin.x}' y2='{fin.y}'/>", file=fichier_svg)
            print("</g>", file=fichier_svg)
    
        print("</g>", file=fichier_svg)
        print("</svg>", file=fichier_svg)
    os.system(f"kitty +kitten icat {nom_image}")

def sous_branche(branche):
    """
    renvoie une sous-branche aleatoire pour la branche donnee
    """
    depart, longueur, angle = branche
    nouveau_depart = depart + Point(cos(angle), sin(angle)) * longueur * uniform(0.7, 1.0)
    nouvelle_longueur = longueur * uniform(0.5, 0.7)
    nouvel_angle = angle + uniform(-pi/3, pi/3)
    return nouveau_depart, nouvelle_longueur, nouvel_angle

def parcours_largeur(element, suivants):
    """
    - suivants est une fonction qui donne les fils d'un element donne
    - element est notre point de depart
    """
    file = deque([element])
    while file:
        courant = file.popleft()
        yield courant
        file.extend(suivants(courant))

def take(iterateur, taille):
    """
    boucle sur les 'taille' premiers elements de l'iterateur
    """
    for index, element in enumerate(iterateur):
        if index >= taille:
            return
        yield element

def main():
    fleurs()


if __name__ == "__main__":
    main()

