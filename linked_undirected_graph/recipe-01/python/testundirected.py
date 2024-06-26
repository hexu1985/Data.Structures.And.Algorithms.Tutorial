"""
File: testundirected.py
"""

from graph import LinkedUndirectedGraph

# Create a directed graph using an adjacency list
g = LinkedUndirectedGraph()

# Add vertices labeled A, B, and C to the graph and print it      
g.addVertex("A")
g.addVertex("B")
g.addVertex("C")
print("Expect vertices ABC and no edges: \n" + str(g))

# Insert edges with weight 2.5 and print the graph
g.addEdge("A", "B", 2.5)
g.addEdge("B", "C", 2.5)
print("Expect same vertices and edges AB BC all with weight 2.5: \n" + str(g))

# Mark all the vertices
for vertex in g.vertices():
    vertex.setMark()

# Print the vertices adjacent to vertex B
print("Expect vertices adjacent to B, namely A C:")
v = g.getVertex("B")
for neighbor in g.neighboringVertices(v.getLabel()):
    print(neighbor)

# Print the edges of vertex B
print("Expect edges incident to B, namely AB BC:")
for edge in g.incidentEdges(v.getLabel()):
    print(edge)
