# This code solves the problem of Number of Operations to Make Network Connected
# The link to this problem on Leetcode is : https://leetcode.com/problems/number-of-operations-to-make-network-connected/description

# Topics: Minimum Spanning Tree, Disjoint Set

class DisjointSet:

    def __init__(self, V):
        self.V = V
        self.rank = [0 for _ in range(V+1)]
        self.parent = [i for i in range(V+1)]

    def findParent(self, x):
        if self.parent[x] == x:
            return x
        
        self.parent[x] = self.findParent(self.parent[x])

        return self.parent[x]

    def unionByRank(self, u, v):

        ulp_u = self.findParent(u)
        ulp_v = self.findParent(v)

        if ulp_u == ulp_v:
            return  

        if self.rank[ulp_u] > self.rank[ulp_v]:
            self.parent[ulp_v] = ulp_u

        elif self.rank[ulp_u] < self.rank[ulp_v]:
            self.parent[ulp_u] = ulp_v
        
        else:
            self.parent[ulp_v]=ulp_u
            self.rank[ulp_u]+=1

class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:

        ds = DisjointSet(n)

        extraEdge = 0

        for edge in connections:

            if ds.findParent(edge[0]) != ds.findParent(edge[1]):
                ds.unionByRank(edge[0], edge[1])
            else:
                extraEdge += 1

        nC = 0

        for i in range(n):
            if ds.findParent(i) == i:
                nC += 1

        if extraEdge >= nC-1:
            return nC-1
        return -1