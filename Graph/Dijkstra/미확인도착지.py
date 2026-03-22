import sys
from heapq import heappush, heappop
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def dij(n, s, adj):
    INF = 10**18
    dist = [INF] * (n + 1)
    dist[s] = 0
    hq = [(0, s)]

    while hq:
        cost, cur = heappop(hq)
        if dist[cur] < cost:
            continue
        for nxt, w in adj[cur]:
            total = cost + w
            if dist[nxt] <= total:
                continue
            dist[nxt] = total
            heappush(hq, (total, nxt))
    return dist


def solve():
    n, m, t = mi()
    s, g, h = mi()
    adj = [[] for _ in range(n+1)]
    w = -1
    for _ in range(m):
        u, v, c = mi()
        adj[u].append((v, c))
        adj[v].append((u,c))
        if (u == g and v == h) or (u == h and v == g): w = c
    
    distS = dij(n, s, adj)
    distH = dij(n, h, adj)
    distG = dij(n, g, adj)

    candidate = []
    for _ in range(t):
        e = int(input())
        if distS[e] == distS[g] + w + distH[e] or distS[e] == distS[h] + w + distG[e]:
            candidate.append(e)
    candidate.sort()
    print(*candidate)

if __name__ == '__main__':
    tc = int(input())
    for _ in range(tc):
        solve()