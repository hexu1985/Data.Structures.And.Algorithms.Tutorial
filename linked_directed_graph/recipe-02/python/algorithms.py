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
            _topoDfs(g, v, lyst)

    return lyst

def _topoDfs(g, v, lyst):
    v.setMark()
    for w in g.neighboringVertices(v.getLabel()):
        if not w.isMarked():
            _topoDfs(g, w, lyst)
    lyst.appendleft(v)


def shortestPaths(g, startLabel):
    # Exercise
    return ["Under development"]


