import sys
from heapq import heappush, heappop
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

n = int()
adj = [[] for _ in range(n)]

def dijkstra(s, e):
    dist = [(1<<31)] * (n+1)
    hq = []
    heappush(hq, (0, s))
    dist[s] = 0
    while hq:
        cost, cur = heappop(hq)
        if dist[cur] < cost: continue
        for w, next in adj[cur]:
            total = cost + w
            if dist[next] <= total: continue
            dist[next] = total
            heappush(hq, (total, next))


def solve():
    dijkstra(1, 100)

if __name__ == '__main__':
    solve()