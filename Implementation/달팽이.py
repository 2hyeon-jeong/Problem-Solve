import sys
input = sys.stdin.readline

dir = [(1, 0), (0, 1), (-1, 0), (0, -1)]
n = int(input())
target = int(input())
grid = [[-1] * n for _ in range(n)]
r = 0
c = 0
d = 0
grid[0][0] = n*n
for i in range(n*n - 1, 0, -1):
    nr = r + dir[d][0]
    nc = c + dir[d][1]
    if (nr < 0 or nr >= n or nc < 0 or nc >= n or grid[nr][nc] != -1):
        d = (d + 1) % 4
        nr = r + dir[d][0]
        nc = c + dir[d][1]
    grid[nr][nc] = i
    r = nr
    c = nc
for g in grid:
    print(*g)

for i in range(n):
    for j in range(n):
        if (grid[i][j] == target): print(i+1, j+1)
