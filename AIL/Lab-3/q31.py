def solve_maze(maze):
    # initialize start and end positions
    start_row, start_col = 0, 0
    end_row, end_col = len(maze) - 1, len(maze[0]) - 1

    # create a visited set to keep track of visited cells
    visited = set()

    # create a stack to implement depth-first search
    stack = [(start_row, start_col)]

    # loop until all possible paths are explored
    while stack:
        row, col = stack.pop()

        # if the current cell is the end cell, we're done
        if row == end_row and col == end_col:
            return True

        # mark the current cell as visited
        visited.add((row, col))

        # check all neighbors of the current cell
        for row_offset, col_offset in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            next_row, next_col = row + row_offset, col + col_offset

            # check if the next cell is within the maze and is not a wall
            if 0 <= next_row < len(maze) and 0 <= next_col < len(maze[0]) and maze[next_row][next_col] != "#" and (next_row, next_col) not in visited:
                # add the next cell to the stack
                stack.append((next_row, next_col))

    # if we reach here, we couldn't find a path to the end cell
    return False

maze = [
    ['.', '.', '.', '#', '.'],
    ['.', '#', '.', '#', ' '],
    ['.', '.', '.', '#', ' '],
    ['#', '#', '.', '#', ' '],
]
if solve_maze(maze):
    print("There is a path from start to end in the maze")
else:
    print("There is no path from start to end in the maze")
