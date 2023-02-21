class Graph:
    def __init__(self,vertices):
        self.V = vertices;
        self.adj = [[0 for cols in range(len(self.V))] for row in range(len(self.V))]
        self.adj_list = {}
    def display_adj_list(self):
        for i in range(len(self.V)):
            for j in range(len(self.V)):
                if self.adj[i][j]>0:
                    if i in self.adj_list:
                        self.adj_list[i] += [self.V[j]]
                    else:
                        self.adj_list[i] = [self.V[j]]
        for i in range(len(self.V)):
            print("Vertex ", self.V[i], ":",end=" ")
            print(self.adj_list[i])
    def add_edge(self,u,v):
        self.adj[self.V.index(u)][self.V.index(v)] = self.adj[self.V.index(v)][self.V.index(u)] =1
    def display_adj_matrix(self):
        for i in range(0,len(self.V)):
            for j in range(0,len(self.V)):
                print(self.adj[i][j],end = " ")
            print()
   
g = Graph(['A','B','C','D','E'])
g.add_edge('A','B')
g.add_edge('A','C')
g.add_edge('A','E')
g.add_edge('B','C')
g.add_edge('B','D')
g.add_edge('C','E')
g.add_edge('C','D')

print("Adjaceny List:")
g.display_adj_list()
print()
print("Adjaceny Matrix:")
g.display_adj_matrix() 