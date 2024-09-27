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


def hasCycle(g):
    for v in g.vertices():
        v.setAttribute("visit_status", "unvisited")

    for v in g.vertices():
        if v.getAttribute("visit_status") == "unvisited":
            if _hasCycleDfs(g, v):
                return True

    return False

def _hasCycleDfs(g, v):
    v.setAttribute("visit_status", "visiting")
    for w in g.neighboringVertices(v.getLabel()):
        visit_status = w.getAttribute("visit_status")
        if visit_status == "unvisited":
            _hasCycleDfs(g, w)
        elif visit_status == "visiting":
            return True

    v.setAttribute("visit_status", "visited")
    return False

