import sys
from heapq import heappop, heappush
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n, m = mi()
    adj = [[] for _ in range(n+1)]
    best = [0] * (n+1)
    for _ in range(m):
        u, v, c = mi()
        adj[u].append((v, c))
        adj[v].append((u, c))
    s, e = mi()
    hq = []
    best[s] = 10**18
    heappush(hq, (-best[s], s))
    while(hq):
        c, node = heappop(hq)
        c *= -1
        if best[node] > c: continue
        for next, w in adj[node]:
            m = min(c, w)
            if best[next] >= m: continue
            heappush(hq, (-m, next))
            best[next] = m
    print(best[e])

if __name__ == '__main__':
    solve()