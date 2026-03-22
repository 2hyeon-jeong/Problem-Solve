import sys
from heapq import heappush, heappop
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n, m = mi()
    adj = [[] for _ in range(n+1)]
    ind = [0] * (n+1)
    for _ in range(m):
        u, v = mi()
        adj[u].append(v)
        ind[v] += 1
    hq = []
    for i in range(1, n+1):
        if ind[i] == 0:
            heappush(hq, i)
    ans = []
    while hq:
        cur = heappop(hq)
        print(cur, end=" ")
        for next in adj[cur]:
            ind[next] -= 1
            if ind[next] == 0:
                heappush(hq, next)


if __name__ == '__main__':
    solve()