from queue import PriorityQueue
 
def tsp_bfs(graph, start):
    # Initialize variables
    visited = set()
    pq = PriorityQueue()
    pq.put((0, start, [start]))
 
    while not pq.empty():
        # Pop the minimum cost path
        cost, node, path = pq.get()
 
        # Check if the path is complete
        if len(path) == len(graph):
            # Add the cost to return to the start node
            cost += graph[node][start]
            path.append(start)
            return cost, path
 
        # Check if the node has been visited
        if node in visited:
            continue
 
        # Mark the node as visited
        visited.add(node)
 
        # Add the neighbors to the priority queue
        for neighbor, distance in graph[node].items():
            if neighbor not in visited:
                new_cost = cost + distance
                new_path = path + [neighbor]
                pq.put((new_cost, neighbor, new_path))
 
    # Return None if no solution is found
    return None
 
# Example usage
graph = {
 'A': {'B': 2, 'C': 3, 'D': 1},
 'B': {'A': 2, 'C': 4, 'D': 2},
 'C': {'A': 3, 'B': 4, 'D': 3},
 'D': {'A': 1, 'B': 2, 'C': 3}
}
start = 'A'
print(tsp_bfs(graph, start))
