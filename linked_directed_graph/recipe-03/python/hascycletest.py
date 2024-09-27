"""
File: topotest.py
"""

from graph import LinkedDirectedGraph
from algorithms import hasCycle

def test_has_cycle_true():
    pass


def test_has_cycle_false():
    g = LinkedDirectedGraph()
    
    # Insert vertices
    g.addVertex("A")
    g.addVertex("B")
    g.addVertex("C")
    g.addVertex("D")
    
    # Insert weighted edges
    g.addEdge("B", "A", 1)
    g.addEdge("B", "D", 1)
    g.addEdge("B", "C", 1)
    g.addEdge("D", "C", 1)
    
    print(g)
    
    print("Neighboring vertices of B:")
    for vertex in g.neighboringVertices("B"):
        print(vertex)
    
    print("Incident edges of A:")
    for edge in g.incidentEdges("A"):
        print(edge)
    
    has_cycle = hasCycle(g)
    print("hasCycle? {}".format(has_cycle))


test_has_cycle_false()
