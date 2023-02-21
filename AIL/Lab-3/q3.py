class Maze:
    def __init__(self, maze):
        self.maze = maze
        self.visited = set()
        self.rows = len(maze)
        self.cols = len(maze[0])
        self.start_row, self.start_col = self.find_start()
        self.cell_nums = [[i+j*self.cols+1 for i in range(self.cols)] for j in range(self.rows)]

    def find_start(self):
        # Find the starting position in the maze
        for i in range(self.rows):
            for j in range(self.cols):
                if self.maze[i][j] == "S":
                    return i, j

    def solve(self):
        # Solve the maze using DFS algorithm
        stack = [(self.start_row, self.start_col)]
        self.visited.add((self.start_row, self.start_col))
        path = []

        while stack:
            row, col = stack.pop()

            if self.maze[row][col] == "E":
                # Exit found, maze is solved
                path.append(self.cell_nums[row][col])
                return path[::-1]

            # Check all four directions
            for i, j in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                new_row, new_col = row + i, col + j

                # Check if the new position is valid and not visited
                if (
                    0 <= new_row < self.rows
                    and 0 <= new_col < self.cols
                    and self.maze[new_row][new_col] != "#"
                    and (new_row, new_col) not in self.visited
                ):
                    stack.append((new_row, new_col))
                    self.visited.add((new_row, new_col))
                    path.append(self.cell_nums[new_row][new_col])

        # Exit not found, maze is unsolvable
        return None

# Test the program with a sample maze
maze = [
    [" ", "S", " ", " ", "E"],
    [" ", "#", " ", "#", " "],
    [" ", " ", "#", " ", " "],
    ["#", " ", " ", " ", " "],
]
m = Maze(maze)
path = m.solve()
if path:
    print(f"Path found: {path}")
else:
    print("Maze is unsolvable!")
