class Graph:
    def __init__(self,edges,n):
        self.adj_List = {}

        for i in range(n):
            self.adj_List[i] = []
        
        for src,dest,weight in edges:
            self.adj_List[src].append((dest,weight))
        
    def printGraph(self):
        for src, dest_weight_List in self.adj_List.items():
            for dest, weight in dest_weight_List:
                print(f'({src} -> {dest} , {weight})',end=' ')
            print()

if __name__ == '__main__':
    edges = [(0,1,6),(1,2,7),(2,0,5),(2,1,4),(3,2,10),(4,5,1),(5,4,3)]
    n = 6
    graph = Graph(edges,n)
    graph.printGraph()