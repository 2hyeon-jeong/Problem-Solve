import sys
from collections import deque
import heapq
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

dir = [(1,0), (0, 1), (-1, 0), (0, -1)]

def solve():
    r, c = mi()
    board = [li() for _ in range(r)]
    aircons = []
    q = deque()
    v = [[[0] * 4 for _ in range(c)] for _ in range(r)]
    for i in range(r):
        for j in range(c):
            if board[i][j] == 9:
                aircons.append((i, j))

    for i, j in aircons:
        for d in range(4):
            q.append((i, j, d))
            v[i][j][d] = 1
    while q:
        i, j, d = q.popleft()
        dr, dc = dir[d]  
        nr = i + dr
        nc = j + dc
        if nr < 0 or nr >= r or nc < 0 or nc >= c: continue
        nd = d
        cell = board[nr][nc]

        if cell == 1:
            if d == 1 or d == 3:
                if not v[nr][nc][d]:
                    v[nr][nc][d] = 1
                continue

        elif cell == 2:
            if d == 0 or d == 2:
                if not v[nr][nc][d]:
                    v[nr][nc][d] = 1
                continue

        elif cell == 3:
            if d == 0: nd = 3
            elif d == 1: nd = 2
            elif d == 2: nd = 1
            else: nd = 0

        elif cell == 4:
            if d == 0: nd = 1
            elif d == 1: nd = 0
            elif d == 2: nd = 3
            else: nd = 2
        if not v[nr][nc][nd]:
            q.append((nr, nc, nd))
            v[nr][nc][nd] = 1
    
    ans = 0
    for i in range(r):
        for j in range(c):
            if v[i][j][0] or v[i][j][1] or v[i][j][2] or v[i][j][3]:
                ans += 1

    print(ans)
if __name__ == '__main__':
    solve()