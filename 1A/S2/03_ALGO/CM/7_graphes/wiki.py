#!/usr/bin/env python3

import sys
import re
import requests
from bs4 import BeautifulSoup
from random import shuffle
from collections import deque

REG = re.compile("/wiki/([a-zA-Z_]+)$")


def voisins(courant):
    # extrait de https://www.geeksforgeeks.org/extract-all-the-urls-from-the-webpage-using-python/
    url = 'https://fr.wikipedia.org/wiki/' + courant
    reqs = requests.get(url)
    soup = BeautifulSoup(reqs.text, 'html.parser')

    urls = []
    uniques = set()
    for link in soup.find_all('a'):
        url = link.get('href')
        if url:
            resultat = REG.match(url)
            if resultat:
                uniques.add(resultat.group(1))
    uniques = list(uniques)
    shuffle(uniques)
    return uniques


def plus_court_chemin(depart, arrivee):
    a_voir = deque()
    a_voir.append(depart)
    vus = set()
    vus.add(depart)

    predecesseurs = dict()

    while a_voir:
        courant = a_voir.popleft()
        for voisin in voisins(courant):
            if voisin in vus:
                continue
            vus.add(voisin)
            predecesseurs[voisin] = courant
            # print("voisin: '", voisin, "' arrivee:'", arrivee, "'")
            if voisin == arrivee:
                return predecesseurs
            print(courant, "->", voisin)
            a_voir.append(voisin)
    return None


def main():
    depart = sys.argv[1]
    arrivee = sys.argv[2]
    predecesseurs = plus_court_chemin(depart, arrivee)

    courant = arrivee
    chemin = [arrivee]
    while courant != depart:
        courant = predecesseurs[courant]
        chemin.append(courant)

    print("****************")
    for mot in reversed(chemin):
        print(mot)


if __name__ == "__main__":
    main()
