
import sys

dist = []

def floyd_warshall(num_nodes):
    global dist
    for k in range(num_nodes):
        for i in range(num_nodes):
            for j in range(num_nodes):
                if dist[i][k] != sys.maxsize and dist[k][j] != sys.maxsize:
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    return dist

def init_graph(num_nodes, edges):
    global dist
    dist = [[sys.maxsize] * num_nodes for _ in range(num_nodes)]
    
    for i in range(num_nodes):
        dist[i][i] = 0
    
    for u, v, weight in edges:
        dist[u][v] = weight

if __name__ == "__main__":
    init_graph(5, [(0, 1, -1), (0, 2, 4), (1, 2, 3), (1, 3, 2), (1, 4, 2), (3, 2, 5), (3, 1, 1), (4, 3, -3)])
    distance = floyd_warshall(5)
    print("Shortest distances between all pairs:")
    for row in distance:
        print(row)
