import sys
from collections import deque
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

dir = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def solve():
    n, m = mi()
    maps = [input().strip() for _ in range(n)]
    v = [[[-1] * 2 for _ in range(m)] for _ in range(n)]
    q = deque()
    q.append((0, 0, 0))
    v[0][0][0] = 1
    while q:
        i, j, is_broken = q.popleft()
        for dr, dc in dir:
            nr = i + dr
            nc = j + dc
            if (nr < 0 or nr >= n or nc < 0 or nc >= m): continue
            if maps[nr][nc] == "1" and not is_broken and v[nr][nc][1] == -1: 
                v[nr][nc][1] = v[i][j][0] + 1
                q.append((nr, nc, 1))
            elif maps[nr][nc] == "0" and v[nr][nc][is_broken] == -1:
                v[nr][nc][is_broken] = v[i][j][is_broken] + 1
                q.append((nr, nc, is_broken))
    if v[n-1][m-1][0] == -1: print(v[n-1][m-1][1])
    elif v[n-1][m-1][1] == -1: print(v[n-1][m-1][0])
    else: print(min(v[n-1][m-1][0], v[n-1][m-1][1]))
if __name__ == '__main__':
    solve()