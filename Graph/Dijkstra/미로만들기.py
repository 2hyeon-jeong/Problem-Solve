import sys
from heapq import heappush, heappop
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

dir = [(1,0), (0, 1), (-1,0), (0,-1)]

def solve():
    n = int(input())
    maps = [input().strip() for _ in range(n)]
    dist = [[(1<<63)] * n for _ in range(n)]
    hq = []
    heappush(hq, (0, 0, 0))
    dist[0][0] = 0
    while hq:
        c, i, j = heappop(hq)
        if dist[i][j] < c: continue
        for dr, dc in dir:
            nr = i + dr
            nc = j + dc
            if (nr < 0 or nr >= n or nc < 0 or nc >= n): continue
            w = 0
            if maps[nr][nc] == "0": w += 1
            total = c + w  
            if dist[nr][nc] <= total: continue
            heappush(hq, (total, nr, nc))
            dist[nr][nc] = total
    print(dist[n-1][n-1])
if __name__ == '__main__':
    solve()