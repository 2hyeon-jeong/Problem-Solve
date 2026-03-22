import sys
from collections import deque
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    a, b = mi()
    n, m = mi()
    adj = [[] for _ in range(n+1)]
    visited = [-1] * (n+1)
    for _ in range(m):
        u, v = mi()
        adj[u].append(v)
        adj[v].append(u)
    q = deque()
    q.append(a)
    visited[a] = 0
    while q:
        cur = q.popleft()
        for next in adj[cur]:
            if visited[next] != -1: continue
            q.append(next)
            visited[next] = visited[cur] + 1
    print(visited[b])

if __name__ == '__main__':
    solve()