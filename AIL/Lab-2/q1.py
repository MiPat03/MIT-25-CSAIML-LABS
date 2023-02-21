class Graph:
    def __init__(self,edges,n):
        self.adj_List = {}

        for i in range(n):
            self.adj_List[i] = []
        
        for src,dest in edges:
            self.adj_List[src].append(dest)
        
    def printGraph(self):
        for src, dest_List in self.adj_List.items():
            for dest in dest_List:
                print(f'({src} -> {dest})',end='')
            print()

if __name__ == '__main__':
    edges = [(0,1),(1,2),(2,0),(2,1),(3,2),(4,5),(5,4)]
    n = 6
    graph = Graph(edges,n)
    graph.printGraph()