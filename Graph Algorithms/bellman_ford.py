
class Edge:
    def __init__(self, u, v, weight):
        self.u = u
        self.v = v
        self.weight = weight

edges = []
distance = []

def bellman_ford(num_nodes, source):
    global distance
    distance = [float('inf')] * num_nodes
    distance[source] = 0

    for _ in range(num_nodes - 1):
        for edge in edges:
            if distance[edge.u] != float('inf') and distance[edge.u] + edge.weight < distance[edge.v]:
                distance[edge.v] = distance[edge.u] + edge.weight
    return distance

def init_graph(num_nodes, edge_list):
    global edges
    edges = [Edge(*edge) for edge in edge_list]

if __name__ == "__main__":
    init_graph(5, [(0, 1, -1), (0, 2, 4), (1, 2, 3), (1, 3, 2), (1, 4, 2), (3, 2, 5), (3, 1, 1), (4, 3, -3)])
    distance = bellman_ford(5, 1)
    print("Shortest distances from source:", distance)
