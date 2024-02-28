#!/usr/bin/env python3

def heappush(tas, priorite):
    indice_nouveau = len(tas)
    tas.append(priorite)
    remontee(tas, indice_nouveau)


def remontee(tas, moi):
    """
    je remonte tant que je suis plus petit que mon pere
    """
    while moi != 0:
        papa = (moi - 1) // 2
        print(moi, papa)
        if tas[moi] > tas[papa]:
            return
        tas[moi], tas[papa] = tas[papa], tas[moi]
        moi = papa


def heappop(tas):
    if len(tas) == 1:
        return tas.pop()
    min_a_renvoyer = tas[0]
    tas[0] = tas.pop()
    descente(tas, 0)
    return min_a_renvoyer


def descente(tas, moi):
    enfants = [2*moi+1, 2*moi+2]
    vrais_enfants = (e for e in enfants if e < len(tas))
    try:
        petit = min(vrais_enfants, key=lambda e: tas[e])
    except ValueError:
        return
    if tas[moi] <= tas[petit]:
        return
    tas[moi], tas[petit] = tas[petit], tas[moi]
    descente(tas, petit)


def main():
    tas = []
    heappush(tas, 3)
    print(tas)
    heappush(tas, 4)
    print(tas)
    heappush(tas, 2)
    print(tas)
    heappush(tas, 5)
    print(tas)
    heappush(tas, 1)
    print(tas)
    heappop(tas)
    print(tas)


main()
