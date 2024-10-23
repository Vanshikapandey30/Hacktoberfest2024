# main.py

from dfs import dfs, init_graph as init_dfs
from bfs import bfs, init_graph as init_bfs
from bellman_ford import bellman_ford, init_graph as init_bellman_ford
from floyd_warshall import floyd_warshall, init_graph as init_floyd_warshall
from dijkstra import dijkstra, init_graph as init_dijkstra

def main():
    # DFS
    init_dfs(5)
    print("\nDFS starting from node 0:")
    dfs(0)
    print()

    # BFS
    init_bfs(5)
    print("\nBFS starting from node 0:")
    bfs(0)
    print()

    # Bellman-Ford
    init_bellman_ford(5, [(0, 1, -1), (0, 2, 4), (1, 2, 3), (1, 3, 2), (1, 4, 2), (3, 2, 5), (3, 1, 1), (4, 3, -3)])
    print("\nDistances from node 0 (Bellman-Ford):")
    distance = bellman_ford(5, 0)
    print(distance)

    # Floyd-Warshall
    init_floyd_warshall(4, [(0, 1, 3), (0, 2, 5), (1, 2, 2), (1, 3, 1), (2, 3, 2)])
    distance = floyd_warshall(4)
    print("\nDistance matrix (Floyd-Warshall):")
    for row in distance:
        print(row)

    # Dijkstra's
    init_dijkstra(5)
    print("\nDistances from node 0 (Dijkstra):")
    distance = dijkstra(5, 0)
    print(distance)

if __name__ == "__main__":
    main()
