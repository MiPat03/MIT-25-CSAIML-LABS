from collections import defaultdict

# define a class for the Graph
class Graph:
    # constructor that initializes the number of vertices and a dictionary to store edges
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.graph = defaultdict(list)
    
    # method to add an edge to the graph
    def add_edge(self, u, v):
        self.graph[u].append(v)
    
    # recursive method to detect cycle in the graph
    def is_cyclic_util(self, v, visited, recursion_stack):
        # mark the current node as visited and add it to the recursion stack
        visited.add(v)
        recursion_stack.add(v)
        
        # traverse all neighbors of the current node
        for neighbor in self.graph[v]:
            # if the neighbor is not visited, recursively check if there is a cycle
            if neighbor not in visited:
                if self.is_cyclic_util(neighbor, visited, recursion_stack):
                    return True
            # if the neighbor is already in the recursion stack, there is a cycle
            elif neighbor in recursion_stack:
                return True
        
        # remove the current node from the recursion stack and return False
        recursion_stack.remove(v)
        return False
    
    # method to detect cycle in the graph
    def is_cyclic(self):
        visited = set()         # set to keep track of visited nodes
        recursion_stack = set() # set to keep track of nodes in recursion stack
        
        # traverse all nodes in the graph
        for v in range(self.num_vertices):
            # if a node is not visited, recursively check if there is a cycle
            if v not in visited:
                if self.is_cyclic_util(v, visited, recursion_stack):
                    return True
        
        # if no cycle is found, return False
        return False

# create a graph with 4 vertices and add edges
g = Graph(4)
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 0)
g.add_edge(2, 3)
g.add_edge(3, 3)

# check if the graph contains a cycle
if g.is_cyclic():
    print("Graph contains a cycle")
else:
    print("Graph does not contain a cycle")
