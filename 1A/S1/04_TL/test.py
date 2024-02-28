# Fichier fredkin.py
import numpy as np
import random
import pygame
import pygame.gfxdraw

_st = {"OFF":0, "ON":1}
_cote = 3
_n = 100

def afficher_naif(screen,tab):
    for i in range(tab.shape[0]):
        for j in range(tab.shape[1]):
            if tab[i,j]==_st["OFF"]:
                c=[50,50,100]
            elif tab[i,j]==_st["ON"]:
                c=[255,255,0]
            else:
                c=[0,0,0]
            pygame.gfxdraw.box(screen, (_cote*i, _cote*j, _cote, _cote), c)
    pygame.display.flip()

def init(tab):
    for i in range(1, tab.shape[0]-1):
        for j in range(1, tab.shape[1]-1):
            tab[i,j] = _st["OFF"]
            if i in range(19 * _n // 40, 21 * _n // 40) and  j in range(19 * _n // 40, 21 * _n // 40) and random.random()>0.5 :
                tab[i,j] = _st["ON"]

def suivant_naif(tab):
    """ Calcule l'étape suivante de l'automate """
    ##########################################
    def comptevoisins(i, j):
        """ Renvoie le nombre de voisins ON de (i,j) """
        c = 0
        for x in range(i-1, i+2) :
            for y in range(j-1, j+2) :
                if tab2[x,y] ==_st["ON"]:
                    c+=1
        if tab2[i][j] == _st["ON"]:
            c-=1
        return c
    ##########################################
    tab2=tab.copy()
    for i in range(1, tab2.shape[0]-1):
        for j in range(1, tab2.shape[1]  -1):
            c=comptevoisins(i, j)
            if c%2==0:
                tab[i,j] = _st["OFF"]
            else:
                tab[i,j] = _st["ON"]

def unesimu(screen,tab):
    init(tab)
    for i in range(10):
        suivant_naif(tab)
        afficher_naif(screen, tab)
        print(i)

def main() :
    pygame.init()
    tab=np.zeros((_n, _n),dtype = np.uint32)
    screen=pygame.display.set_mode((_n * _cote, _n * _cote))
    unesimu(screen, tab)
    pygame.quit()

main()