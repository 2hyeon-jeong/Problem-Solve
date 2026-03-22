import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    adj = [[] for _ in range(n+1)]
    parent = [0] * (n+1)
    for _ in range(n-1):
        u, v = mi()
        adj[u].append(v)
        adj[v].append(u)
    def dfs(cur, par):
        parent[cur] = par
        for next in adj[cur]:
            if next == par: continue
            dfs(next, cur)
    dfs(1, -1)
    for p in parent[2:]:
        print(p)

if __name__ == '__main__':
    solve()