"""
File: algorithms.py

Graph processing algorithms
"""

import collections

def topoSort(g, startLabel = None):  
    lyst = collections.deque()
    g.clearVertexMarks()
    for v in g.vertices():
        if not v.isMarked():
            dfs(g, v, lyst)

    return lyst

def dfs(g, v, lyst):
    v.setMark()
    for w in g.neighboringVertices(v.getLabel()):
        if not w.isMarked():
            dfs(g, w, lyst)
    lyst.appendleft(v)


def shortestPaths(g, startLabel):
    # Exercise
    return ["Under development"]

def spanTree(g, startLabel):
    # Exercise
    return ["Under development"]


