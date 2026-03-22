import sys
from collections import deque
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n, k = mi()
    t = [0] + li()
    adj = [[] for _ in range(n+1)]
    degree = [0] * (n+1)
    for _ in range(k):
        u, v = mi()
        adj[u].append(v)
        degree[v] += 1
    w = int(input())
    q = deque()
    ans = 0
    dp = [0] * (n+1)
    for i in range(1, n+1):
        dp[i] = t[i]
    
    for i in range(1, n+1):
        if degree[i] == 0: q.append(i)
    while q:
        cur = q.popleft()
        for next in adj[cur]:
            degree[next] -= 1
            dp[next] = max(dp[next], dp[cur] + t[next])
            if degree[next] == 0:
                q.append(next)

    print(dp[w])

if __name__ == '__main__':
    tc = int(input())
    for _ in range(tc):
        solve() 