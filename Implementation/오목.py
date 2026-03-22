import sys
input = sys.stdin.readline
n = 19
grid = []
dir = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)] # 12시부터 시작하는 시계방향
for _ in range(n):
    r = list(map(int, input().split()))
    grid.append(r)
found = False
for i in range(n):
    for j in range(n):
        if found: continue
        if (grid[i][j] == 0): continue
        cur_color = grid[i][j]
        for k in range(4):
            cnt = 1
            ans = [(i, j)]
            for l in range(2):
                nr = i
                nc = j
                dr, dc = dir[k + 4*l]
                while True:
                    nr += dr
                    nc += dc
                    if (nr < 0 or nr >= n or nc < 0 or nc >= n or cur_color != grid[nr][nc]): break
                    cnt += 1
                    ans.append((nr, nc))
            if cnt == 5:
                print(cur_color)
                r, c = min(ans, key=lambda x: (x[1], x[0]))
                print(f"{r+1} {c + 1}")
                sys.exit(0)
print(0)