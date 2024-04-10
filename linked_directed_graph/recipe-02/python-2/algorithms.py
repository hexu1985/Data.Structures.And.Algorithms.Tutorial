"""
File: algorithms.py

Graph processing algorithms
"""

from toposort import TopoSorter

def topoSort(g, startLabel = None):
    topo_sorter = TopoSorter(g)
    return topo_sorter.sort()


def shortestPaths(g, startLabel):
    # Exercise
    return ["Under development"]

def spanTree(g, startLabel):
    # Exercise
    return ["Under development"]


