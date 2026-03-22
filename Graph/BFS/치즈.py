import sys
from collections import deque
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

dir = [(1,0), (0, 1), (-1,0), (0, -1)]

def bfs(maps, n, m):
    s = (0, 0)
    q = deque()
    v = [[0] * m for _ in range(n)]
    q.append(s)
    v[0][0] = 1
    rem = []
    while q:
        r, c = q.popleft()
        for dr, dc in dir:
            nr = r + dr
            nc = c + dc
            if not (0 <= nr < n and 0 <= nc < m): continue
            if v[nr][nc]: continue
            if maps[nr][nc] == 1: 
                v[nr][nc] = 1
                rem.append((nr, nc))
                continue
            v[nr][nc] = 1
            q.append((nr, nc))
    ret = len(rem)
    for i, j in rem:
        maps[i][j] = 0
    return ret

def solve():
    r, c = mi()
    maps = [li() for _ in range(r)]
    cheese = 0
    for i in maps:
        cheese += sum(i)
    ans = 0
    time = 0
    while cheese > 0:
        temp = bfs(maps, r, c)
        if (cheese - temp <= 0):
            ans = cheese
        cheese -= temp
        time += 1
    print(time, ans)
        

if __name__ == '__main__':
    solve()