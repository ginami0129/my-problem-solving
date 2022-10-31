import sys

input = sys.stdin.readline


def makeSet(u):
    p[u] = u
    rank[u] = 1
    size[u] = 1


# Path Comnpression
def findSet(u):
    if p[u] != u:
        p[u] = findSet(p[u])
    return p[u]


# Union By Rank
def union(u, v):
    u, v = findSet(u), findSet(v)
    if rank[u] > rank[v]:
        p[v] = u
        size[u] += size[v]
    else:
        p[u] = v
        size[v] += size[u]
        if rank[u] == rank[v]:
            rank[v] += 1


if __name__ == "__main__":
    T = int(input())
    while T:
        F = int(input())
        p, size, rank = {}, {}, {}
        for _ in range(F):
            u, v = input().split(" ")
            if u not in p:
                makeSet(u)
            if v not in p:
                makeSet(v)
            print(union(u, v))
        T -= 1
