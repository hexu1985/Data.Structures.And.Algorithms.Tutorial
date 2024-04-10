class TopoSorter:
    def __init__(self, g):
        self.g = g

    def sort(self):
        self.g.clearVertexMarks()
        self.curLabel = self.g.sizeVertices()
        self.f = dict()

        for v in self.g.vertices():
            if not v.isMarked():
                self.dfs_topo(v)

        vertices = self.f.items()
        vertices = sorted(vertices, key=lambda v: v[1])
        return [v[0] for v in vertices]

    def dfs_topo(self, s):
        s.setMark()
        for v in self.g.neighboringVertices(s.getLabel()):
            if not v.isMarked():
                self.dfs_topo(v)
        self.f[s.getLabel()] = self.curLabel
        self.curLabel = self.curLabel - 1

