"""
File: algorithms.py

Graph processing algorithms
"""

import collections
from heapq import heappop, heappush

INFINITY = "-"

def shortestPaths(g, startLabel):
    # Exercise
    return ["Under development"]

def spanTree(g, startLabel):
    leastCostEdges = []
    P = prim(g, g.getVertex(startLabel))
    for u, v in P.items():
        if v is None: continue
        leastCostEdges.append(g.getEdge(u.getLabel(), v.getLabel()))
    return leastCostEdges

def prim(g, s):
    P, Q = {}, [(0, None, s)]
    while Q:
        _, p, u = heappop(Q)
        if u in P:
            continue
        P[u] = p
        for e in u.incidentEdges():
            heappush(Q, (e.getWeight(), u, e.getOtherVertex(u)))
    return P


