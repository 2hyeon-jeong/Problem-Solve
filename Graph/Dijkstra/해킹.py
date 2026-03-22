import sys
from heapq import heappop, heappush
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n, d, c = mi()
    adj = [[] for _ in range(n+1)]
    inf = (1<<31)
    dist = [inf] * (n+1)
    for _ in range(d):
        v, u, s = mi()
        adj[u].append((v, s))
    
    hq = []
    heappush(hq, (0, c))
    dist[c] = 0
    while hq:
        cost, node = heappop(hq)
        if dist[node] < cost: continue
        for next, w in adj[node]:
            total = cost + w
            if dist[next] > total:
                dist[next] = total
                heappush(hq, (total, next))
    cnt = 0
    time = 0
    for i in range(1, n+1):
        if dist[i] == inf: continue
        time = max(time, dist[i])
        cnt += 1
    print(cnt, time)
if __name__ == '__main__':
    tc = int(input())
    for _ in range(tc):
        solve()
