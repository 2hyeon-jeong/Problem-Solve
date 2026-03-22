import sys
from collections import deque
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

dir = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def solve():
    n, m, k = mi()
    maps = [input().strip() for _ in range(n)]
    q = deque()
    v = [[[-1] * (k + 1) for _ in range(m)] for _ in range(n)]
    q.append((0, 0, 0))
    v[0][0][0] = 1
    while q:
        i, j, broken_cnt = q.popleft()
        for dr, dc in dir:
            nr = i + dr
            nc = j + dc
            if not (0 <= nr < n and 0 <= nc < m): continue
            if maps[nr][nc] == "1" and broken_cnt < k and v[nr][nc][broken_cnt + 1] == -1:
                if v[i][j][broken_cnt] % 2 == 1: #낮
                    v[nr][nc][broken_cnt + 1] = v[i][j][broken_cnt] + 1
                    q.append((nr, nc, broken_cnt + 1))
                else: #밤
                    v[nr][nc][broken_cnt + 1] = v[i][j][broken_cnt] + 2
                    q.append((nr, nc, broken_cnt + 1))
            elif maps[nr][nc] == "0" and v[nr][nc][broken_cnt] == -1:
                v[nr][nc][broken_cnt] = v[i][j][broken_cnt] + 1
                q.append((nr, nc, broken_cnt))
    
    ans = (1<<30)
    for i in range(k+1):
        if v[n-1][m-1][i] == -1: continue
        ans = min(v[n-1][m-1][i], ans)
    if (ans == (1<<30)): print(-1)
    else: print(ans)


if __name__ == '__main__':
    solve()