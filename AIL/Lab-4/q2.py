from collections import defaultdict, deque
 
class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
 
    def addEdge(self, u, v):
        self.graph[u].append(v)
 
    def isCyclic(self):
        visited = [False] * (len(self.graph))
        stack = [False] * (len(self.graph))
        for node in range(len(self.graph)):
            if visited[node] == False:
                if self.isCyclicUtil(node, visited, stack) == True:
                    return True
        return False
 
    def isCyclicUtil(self, node, visited, stack):
        visited[node] = True
        stack[node] = True
        for neighbour in self.graph[node]:
            if visited[neighbour] == False:
                if self.isCyclicUtil(neighbour, visited, stack) == True:
                    return True
            elif stack[neighbour] == True:
                return True
        stack[node] = False
        return False
 
g = Graph()
g.addEdge(0, 1)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(3, 4)
g.addEdge(4, 5)
 
if g.isCyclic() == True:
    print("Graph contains cycle")
else:
    print("Graph does not contain cycle")
