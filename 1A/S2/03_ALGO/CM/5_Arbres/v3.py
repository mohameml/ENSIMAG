#!/usr/bin/env python3

from math import pi, cos, sin
from random import randint, uniform
import os

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, autre):
        return Point(self.x+autre.x, self.y+autre.y)

    def __mul__(self, scalaire):
        return Point(self.x*scalaire, self.y*scalaire)


class Noeud:
    def __init__(self, branche):
        self.branche = branche
        self.enfants = []
        self.taille = 1

    def parcours_profondeur(self):
        yield self
        for fils in self.enfants:
            yield from fils.parcours_profondeur()

    def remplir(self):
        depart, longueur, angle = self.branche
        if longueur < 3:
            return
        for _ in range(randint(2, 5)):
            nouveau_depart = depart + Point(cos(angle), sin(angle)) * longueur * uniform(0.7, 1.0)
            nouvelle_longueur = longueur * uniform(0.5, 0.7)
            nouvel_angle = angle + uniform(-pi/3, pi/3)
            fils = Noeud((nouveau_depart, nouvelle_longueur, nouvel_angle))
            fils.remplir()
            self.enfants.append(fils)
            self.taille += fils.taille

    def svg(self, fichier_svg):
        depart, longueur, angle = self.branche
        fin = depart + Point(cos(angle), sin(angle)) * longueur
        print(f"<line x1='{depart.x}' y1='{depart.y}' x2='{fin.x}' y2='{fin.y}'/>", file=fichier_svg)


class Arbre:
    def __init__(self):
        self.racine = Noeud((Point(400, 580), 250, -pi/2))
        self.racine.remplir()

    def __len__(self):
        return self.racine.taille

    def __iter__(self):
        return self.racine.parcours_profondeur()

    COMPTE_IMAGE=0
    def svg(self):
        nom_image = f"img_{self.COMPTE_IMAGE}.svg"
        with open(nom_image, 'w') as fichier_svg:
            print("<svg width='800' height='600'>", file=fichier_svg)
            print("<g stroke-width='0.5%' stroke='black'>", file=fichier_svg)
            for noeud in self:
                noeud.svg(fichier_svg)
            print("</g>", file=fichier_svg)
            print("</svg>", file=fichier_svg)
        os.system(f"kitty +kitten icat {nom_image}")

def main():
    a = Arbre()
    a.svg()


if __name__ == "__main__":
    main()

