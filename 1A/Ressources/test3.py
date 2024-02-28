#!/usr/bin/env python3

from collections import deque


def tri_topologique(graph):
    """
    Tri topologique d'un graphe orienté acyclique (DAG).
    :param graph: dictionnaire représentant le graphe
    :return: liste ordonnée des sommets
    """
    in_degree = {v: 0 for v in graph}
    for v in graph:
        for neighbor in graph[v]:
            in_degree[neighbor] += 1

    queue = deque([v for v in graph if in_degree[v] == 0])
    order = []

    while queue:
        v = queue.popleft()
        order.append(v)

        for neighbor in graph[v]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)

    if len(order) != len(graph):
        raise ValueError("Le graphe contient un cycle.")

    return order


# Test de la fonction tri_topologique
graph = {
    "A": {"B"},
    "B": {"C"},
    "C": {"D", "A"},
    "D": {"E", "F"},
    "E": {},
    "F": {}
}

print(tri_topologique(graph))
