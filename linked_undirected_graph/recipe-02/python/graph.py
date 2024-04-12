"""
File: graph.py
"""

#from abstractcollection import AbstractCollection

class LinkedEdge:

    # An edge has two vertices,
    # a weight, and a mark attribute.
    
    def __init__(self, vertex1, vertex2, weight = None):         
        self._vertex1 = vertex1
        self._vertex2 = vertex2
        self._weight = weight 
        self._mark = False
    
    def clearMark(self):
        """Clears the mark on the edge."""
        self._mark = False
    
    def __eq__(self, other):
        """Two edges are equal if they connect
        the same vertices."""
        if self is other: return True
        if type(self) != type(other):
            return False
        return (self._vertex1 == other._vertex1 and self._vertex2 == other._vertex2) or \
            (self._vertex1 == other._vertex2 and self._vertex2 == other._vertex1) 

    def containsVertex(self, vertex):
        if vertex == self._vertex1 or vertex == self._vertex2:
            return True
        else:
            return False

    def getVertex1(self):
        return self._vertex1

    def getVertex2(self):
        return self._vertex2
    
    def getOtherVertex(self, thisVertex):
        """Returns the vertex opposite thisVertex."""
        if thisVertex == None or thisVertex == self._vertex2:
            return self._vertex1
        else:
            return self._vertex2

    def getWeight(self):
        """Returns the edge's weight."""
        return self._weight
    
    def isMarked(self):
        """Returns True if the edge is marked
        or False otherwise."""
        return self._mark
    
    def setMark(self):
        """Sets the mark on the edge."""
        self._mark = True
    
    def setWeight(self, weight):
        """Sets the weight on the edge to weight."""
        self._weight = weight     
          
    def __str__(self):
        """Returns the string representation of the edge."""
        return str(self._vertex1) + ">" + \
               str(self._vertex2)   + ":" + \
               str(self._weight)

    def __hash__(self):
        """Supports hashing on a edge."""
        return hash((self._vertex1, self._vertex2, self._weight))

class LinkedVertex:

    # A vertex has a label, a list of incident edges,
    # and a mark attribute.

    def __init__(self, label):
        self._label = label
        self._edgeList = list()
        self._mark = False

    def clearMark(self):
        """Clears the mark on the vertex."""
        self._mark = False
    
    def getLabel(self):
        """Returns the label of the vertex."""
        return self._label
    
    def isMarked(self):
        """Returns True if the vertex is marked
        or False otherwise."""
        return self._mark
    
    def setLabel(self, label, g):
        """Sets the vertex's label to label."""
        g._vertices.pop(self._label, None)
        g._vertices[label] = self
        self._label = label          

    def setMark(self):
        """Sets the mark on the vertex."""
        self._mark = True
    
    def __str__(self):
        """Returns the string representation of the vertex."""
        return str(self._label)

    def __eq__(self, other):
        """Two vertices are equal if they have
        the same labels."""
        if self is other: return True
        if type(self) != type(other): return False
        return self.getLabel() == other.getLabel()

    def __lt__(self, other):
        return str(self) < str(other)

    # Methods used by LinkedGraph

    def addEdge(self, edge):
        """Connects the vertices with an edge."""
        if not edge.containsVertex(self):
            raise AttributeError("{} not vertex of {}".format())
        self._edgeList.append(edge)
    
    def addEdgeTo(self, toVertex, weight):
        """Connects the vertices with an edge."""
        edge = LinkedEdge(self, toVertex, weight)
        self._edgeList.append(edge)
    
    def getEdgeTo(self, toVertex):
        """Returns the connecting edge if it exists, or
        None otherwise."""
        edge = LinkedEdge(self, toVertex)
        try:
            return self._edgeList[self._edgeList.index(edge)]
        except:
            return None

    def incidentEdges(self):
        """Returns the incident edges of this vertex."""
        return iter(self._edgeList)
        
    def neighboringVertices(self):
        """Returns the neighboring vertices of this vertex."""
        vertices = list()
        for edge in self._edgeList:
            vertices.append(edge.getOtherVertex(self))
        return iter(vertices)
            
    def removeEdgeTo(self, toVertex):
        """Returns True if the edge exists and is removed,
        or False otherwise."""
        edge = LinkedEdge(self, toVertex)
        if edge in self._edgeList:
            self._edgeList.remove(edge)
            return True
        else:
            return False

    def __hash__(self):
        """Supports hashing on a vertex."""
        return hash(self._label)


class LinkedUndirectedGraph:

    # A graph has a count of vertices, a count of edges,
    # and a dictionary of label/vertex pairs.

    def __init__(self, vertices=None):
        self._size = 0
        self._edgeCount = 0
        self._vertices = {}
        if vertices:
            for vertex in vertices:
                self.addVertex(vertex)
        
    def __len__(self):
        """-> The number of items in self."""
        return self._size

    def isEmpty(self):
        return len(self) == 0

    # Methods for clearing, marks, sizes, string rep

    def clear(self):
        """Clears the graph."""
        self._size = 0
        self._edgeCount = 0
        self._vertices = {}        

    def clearEdgeMarks(self):
        """Clears all the edge marks."""
        for edge in self.edges():
            edge.clearMark()
    
    def clearVertexMarks(self):
        """Clears all the vertex marks."""
        for vertex in self.vertices():
            vertex.clearMark()
    
    def sizeEdges(self):
        """Returns the number of edges."""
        return self._edgeCount
    
    def sizeVertices(self):
        """Returns the number of vertices."""
        return len(self)
    
    def __str__(self):
        """Returns the string representation of the graph."""
        result = str(self.sizeVertices()) + " Vertices: "
        for vertex in self._vertices:
            result += " " + str(vertex)
        result += "\n";
        result += str(self.sizeEdges()) + " Edges: "
        for edge in self.edges():
            result += " " + str(edge)
        return result

    # Vertex related methods
    
    def addVertex(self, label):
        """Adds a vertex with the given label to the graph."""
        self._vertices[label] = LinkedVertex(label)
        self._size += 1
        
    def containsVertex (self, label):
        return label in self._vertices
    
    def getVertex(self, label):
        return self._vertices[label]
    
    def removeVertex(self,  label):
        """Returns True if the vertex was removed, or False otherwise."""
        removedVertex = self._vertices.pop(label, None)
        if removedVertex is None: 
            return False
        
        # Examine all other vertices to remove edges
        # directed at the removed vertex
        for vertex in self.vertices():
            if vertex.removeEdgeTo(removedVertex): 
                self._edgeCount -= 1

        self._size -= 1
        return True
    
    # Methods related to edges

    def addEdge(self, fromLabel, toLabel, weight):
        """Connects the vertices with an edge with the given weight."""
        fromVertex = self.getVertex(fromLabel)
        toVertex   = self.getVertex(toLabel)
        edge = LinkedEdge(fromVertex, toVertex, weight)
        fromVertex.addEdge(edge)
        toVertex.addEdge(edge)
        self._edgeCount += 1
    
    def containsEdge(self, fromLabel, toLabel):
        """Returns True if an edge connects the vertices,
        or False otherwise."""
        return self.getEdge(fromLabel, toLabel) != None
    
    def getEdge(self, fromLabel, toLabel):
        """Returns the edge connecting the two vertices, or None if
        no edge exists."""
        fromVertex = self.getVertex(fromLabel)
        toVertex   = self.getVertex(toLabel)
        return fromVertex.getEdgeTo(toVertex)
    
    def removeEdge(self, fromLabel, toLabel): 
        """Returns True if the edge was removed, or False otherwise."""
        fromVertex = self.getVertex(fromLabel)     
        toVertex   = self.getVertex(toLabel)     
        edgeRemovedFlg = fromVertex.removeEdgeTo(toVertex)
        toVertex.removeEdgeTo(fromVertex)
        if edgeRemovedFlg: 
            self._edgeCount -= 1
        return edgeRemovedFlg

    # Iterators
    
    def __iter__(self):
        """Supports iteration over a view of self (the vertices)."""
        return self.vertices()

    def edges(self):
        """Supports iteration over the edges in the graph."""
        result = list()
        for vertex in self.vertices():
            result += list(vertex.incidentEdges())
        return iter(set(result))
    
    def vertices(self):
        """Supports iteration over the vertices in the graph."""
        return iter(self._vertices.values())

    def incidentEdges(self, label):
        """Supports iteration over the incident edges of the
        given vertex."""
        return self.getVertex(label).incidentEdges()
    
    def neighboringVertices(self, label):
        """Supports iteration over the neighboring vertices of the
        given vertex."""
        return self.getVertex(label).neighboringVertices()
    
