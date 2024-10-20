infinity = float("inf")


def make_graph():
    return {
        1: [(-2, 3)],
        2: [(4, 1), (3, 3)],
        3: [(2, 4)],
        4: [(-1, 2)],
    }


def floyd_warshall(G):
    size = len(G)

    matrix = [ [infinity]*size for i in range(size) ]

    for i in range(size):
        matrix[i][i] = 0

    for node, edges in G.items():
        for edge in edges:
            cost = edge[0]
            to_node = edge[1]

            matrix[node-1][to_node-1] = cost

    for k in range(size):
        for i in range(size):
            for j in range(size):
                if matrix[i][j] > matrix[i][k] + matrix[k][j]:
                    matrix[i][j] = matrix[i][k] + matrix[k][j]

    return matrix


def main():
    G = make_graph()

    shortest_path_matrix = floyd_warshall(G)

    print(f'Shortest path matrix:\n')
    for item in shortest_path_matrix:
        print(item)


main()