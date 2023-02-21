from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        # Initialize an empty defaultdict where each value is a list
        self.graph = defaultdict(list)
        # Set the number of vertices in the graph
        self.V = vertices

    def addEdge(self, u, v):
        # Add vertex v to the adjacency list of vertex u
        self.graph[u].append(v)

    def topologicalSortUtil(self, v, visited, stack):
        # Mark the current vertex as visited
        visited[v] = True
        # Recursively call topologicalSortUtil on each unvisited neighbor
        for i in self.graph[v]:
            if visited[i] == False:
                self.topologicalSortUtil(i, visited, stack)
        # Add the current vertex to the stack once all neighbors have been visited
        stack.append(v)

    def topologicalSort(self):
        # Initialize an empty list to keep track of visited vertices
        visited = [False] * self.V
        # Initialize an empty stack to keep track of the order of visited vertices
        stack = []
        # Call topologicalSortUtil on each unvisited vertex in the graph
        for i in range(self.V):
            if visited[i] == False:
                self.topologicalSortUtil(i, visited, stack)
        # Print the contents of the stack in reverse order to get the topological ordering
        print(stack[::-1])


# Example usage
if __name__ == '__main__':
    # Create a graph with 6 vertices
    g = Graph(6)
    # Add edges to the graph
    g.addEdge(5, 2)
    g.addEdge(5, 0)
    g.addEdge(4, 0)
    g.addEdge(4, 1)
    g.addEdge(2, 3)
    g.addEdge(3, 1)
    # Perform topological sort on the graph and print the result
    g.topologicalSort()  # prints [5, 4, 2, 3, 1, 0]
