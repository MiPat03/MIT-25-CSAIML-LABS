from collections import deque, defaultdict

class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adj_list = defaultdict(list)
        self.in_degree = [0] * num_vertices

    def add_edge(self, u, v):
        self.adj_list[u].append(v)
        self.in_degree[v] += 1

    def topological_sort(self):
        result = []
        zero_in_degree_queue = deque()
        
        # Add all vertices with in-degree of 0 to the queue
        for i in range(self.num_vertices):
            if self.in_degree[i] == 0:
                zero_in_degree_queue.append(i)

        while zero_in_degree_queue:
            # Get the next vertex with in-degree of 0 and add it to the result
            vertex = zero_in_degree_queue.popleft()
            result.append(vertex)

            # Decrease the in-degree of all its neighbors by 1
            for neighbor in self.adj_list[vertex]:
                self.in_degree[neighbor] -= 1

                # If the neighbor now has an in-degree of 0, add it to the queue
                if self.in_degree[neighbor] == 0:
                    zero_in_degree_queue.append(neighbor)

        # If not all vertices were visited, there must be a cycle in the graph
        if len(result) != self.num_vertices:
            print("There exists a cycle in the graph")
        else:
            print(result)
g = Graph(6)
g.add_edge(5, 2)
g.add_edge(5, 0)
g.add_edge(4, 0)
g.add_edge(4, 1)
g.add_edge(2, 3)
g.add_edge(3, 1)

print("Following is a Topological Sort of the given graph")
g.topological_sort()
