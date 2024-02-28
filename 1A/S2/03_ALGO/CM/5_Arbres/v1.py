#!/usr/bin/env python3

from math import pi, cos, sin
from random import randint, uniform

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


class Arbre:
    def __init__(self, racine):
        self.racine = racine

    def __len__(self):
        return self.racine.taille


def fractale(depart, longueur, angle):
    if longueur < 3:
        return
    fin = depart + Point(cos(angle), sin(angle)) * longueur
    print(f"<line x1='{depart.x}' y1='{depart.y}' x2='{fin.x}' y2='{fin.y}'/>")
    for _ in range(randint(2, 5)):
        nouveau_depart = depart + Point(cos(angle), sin(angle)) * longueur * uniform(0.7, 1.0)
        nouvelle_longueur = longueur * uniform(0.5, 0.7)
        nouvel_angle = angle + uniform(-pi/3, pi/3)
        fractale(nouveau_depart, nouvelle_longueur, nouvel_angle)


def main():
    print("<svg width='800' height='600'>")
    print("<g stroke-width='0.5%' stroke='black'>")
    fractale(Point(400, 580), 250, -pi/2)
    print("</g>")
    print("</svg>")


if __name__ == "__main__":
    main()

