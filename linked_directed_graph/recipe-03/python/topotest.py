"""
File: topotest.py
"""

from graph import LinkedDirectedGraph
from algorithms import topoSort

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

topo_list = topoSort(g)
print("TopoSort:")
print(" ".join(map(str, topo_list)))

