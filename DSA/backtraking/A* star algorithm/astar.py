import heapq

# Helper function to calculate heuristic (Manhattan distance in this case)
def heuristic(node, goal):
    return abs(node[0] - goal[0]) + abs(node[1] - goal[1])

# A* algorithm
def a_star_algorithm(start, goal, grid):
    # Create open set (min heap) and closed set
    open_set = []
    heapq.heappush(open_set, (0, start))  # push the start node with f(start) = 0
    came_from = {}  # For path reconstruction
    g_score = {start: 0}  # Cost from start to each node, initially 0 for the start
    f_score = {start: heuristic(start, goal)}  # Estimate for total cost (f = g + h)
    
    while open_set:
        # Get the node with the lowest f_score
        current = heapq.heappop(open_set)[1]
        
        # If goal is reached, reconstruct the path
        if current == goal:
            return reconstruct_path(came_from, current)
        
        # Mark the node as evaluated by adding it to the closed set
        for neighbor in get_neighbors(current, grid):
            tentative_g_score = g_score[current] + 1  # assuming uniform cost for each step

            # If this path to neighbor is better than any previous one, update the scores
            if neighbor not in g_score or tentative_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = g_score[neighbor] + heuristic(neighbor, goal)

                # If neighbor is not in the open set, add it
                if not any(neighbor == i[1] for i in open_set):
                    heapq.heappush(open_set, (f_score[neighbor], neighbor))
    
    return False  # If we exit the loop without finding a path, return failure

# Helper function to reconstruct the path from start to goal
def reconstruct_path(came_from, current):
    total_path = [current]
    while current in came_from:
        current = came_from[current]
        total_path.append(current)
    return total_path[::-1]  # Reverse the path to get it from start to goal

# Helper function to get the neighbors of the current node (considering up, down, left, right moves)
def get_neighbors(node, grid):
    neighbors = []
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # 4 possible directions (N, E, S, W)
    for direction in directions:
        neighbor = (node[0] + direction[0], node[1] + direction[1])
        if 0 <= neighbor[0] < len(grid) and 0 <= neighbor[1] < len(grid[0]) and grid[neighbor[0]][neighbor[1]] == 0:
            neighbors.append(neighbor)
    return neighbors

# Sample grid (0 is walkable, 1 is blocked)
grid = [
    [0, 1, 0, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 0]
]

start = (0, 0)
goal = (4, 4)

path = a_star_algorithm(start, goal, grid)
if path:
    print("Path found:", path)
else:
    print("No path found.")
