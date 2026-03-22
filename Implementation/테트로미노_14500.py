import sys
import math
from collections import deque, Counter
from heapq import heapify, heappush, heappop
from bisect import bisect_left, bisect_right

# sys.setrecursionlimit(10**6)

input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

tets = [
    [(0, 0), (0, 1), (0, 2), (0, 3)],
    [(0, 0), (1, 0), (0, 1), (1, 1)],
    [(0, 0), (1, 0), (2, 0), (2, 1)],
    [(0, 0), (1, 0), (1, 1), (2, 1)],
    [(0, 0), (0, 1), (0, 2), (1, 1)]
]

def solve():
    n, m = mi()
    grid = [[0] * m for _ in range(n)]
    for i in range(n):
        t = li()
        for j in range(len(t)):
            grid[i][j] = t[j]
        
    
    def rotate(grid):
        n = len(grid)
        m = len(grid[0])
        ret = [[0] * n for _ in range(m)]
        for i in range(n):
            for j in range(m):
                ret[j][n - 1 - i] = grid[i][j]
        return ret

    def flip(grid):
        n = len(grid)
        m = len(grid[0])
        ret = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                ret[i][m - 1 - j] = grid[i][j]
        return ret

    ans = 0
    for _ in range(4):
        for cur_grid in (grid, flip(grid)):
            cur_n = len(cur_grid)
            cur_m = len(cur_grid[0])
            for i in range(cur_n):
                for j in range(cur_m):
                    for tet in tets:
                        out_of_range = False
                        t = 0
                        for r, c in tet:
                            nr, nc = i + r, j + c
                            if nr < 0 or nr >= cur_n or nc < 0 or nc >= cur_m:
                                out_of_range = True
                                break
                            t += cur_grid[nr][nc]
                        if out_of_range:
                            continue
                        ans = max(ans, t)
        grid = rotate(grid)

    print(ans)


if __name__ == '__main__':
    solve()
