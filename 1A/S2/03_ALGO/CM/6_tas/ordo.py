#!/usr/bin/env python3
from random import randint
from itertools import cycle
from heapq import heappush, heappop


def main():
    taches = (randint(50, 150) for _ in range(10))
    couleurs = ["red", "green", "blue", "purple", "yellow"]
    print("<svg width='800' height='600'>")
    evenements = list((0, i) for i in range(4))

    for tache, couleur in zip(taches, cycle(couleurs)):
        temps, machine = heappop(evenements)
        print(
            f"<rect x='{temps}' y='{machine*150}' width='{tache}' height='{150}' fill='{couleur}'/>")
        heappush(evenements, (temps+tache, machine))

    print("</svg>")


main()
