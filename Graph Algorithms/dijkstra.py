
import sys

distance = []
visited = []
graph = []

def min_distance(num_nodes):
    min_value = sys.maxsize
    min_index = -1

    for v in range(num_nodes):
        if not visited[v] and distance[v] < min_value:
            min_value = distance[v]
            min_index = v
            
    return min_index

def dijkstra(num_nodes, source):
    global distance, visited
    distance = [sys.maxsize] * num_nodes
    visited = [False] * num_nodes
    distance[source] = 0

    for _ in range(num_nodes - 1):
        u = min_distance(num_nodes)
        visited[u] = True

        for v in range(num_nodes):
            if (graph[u][v] and not visited[v] and
                    distance[u] != sys.maxsize and
                    distance[u] + graph[u][v] < distance[v]):
                distance[v] = distance[u] + graph[u][v]

    return distance

def init_graph(num_nodes):
    global graph
    graph = [[0] * num_nodes for _ in range(num_nodes)]
    
    graph[0][1] = 10
    graph[0][2] = 3
    graph[1][2] = 1
    graph[1][3] = 2
    graph[2][1] = 4
    graph[2][3] = 8
    graph[2][4] = 2
    graph[3][4] = 7
    graph[4][3] = 9

if __name__ == "__main__":
    init_graph(5)
    distance = dijkstra(5, 0)
    print("Shortest distances from source:", distance)