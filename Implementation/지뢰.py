import sys
input = sys.stdin.readline

dr = [-1, -1, 0, 1, 1, 1, 0, -1]
dc = [0, 1, 1, 1, 0, -1, -1, -1]

n = int(input())
grid = []
input_grid = []
clicked = False
for _ in range(n):
    grid.append(input().strip())

for i in range(n):
    row = input().strip()
    input_grid.append(row)
    for j in range(n):
        if (row[j] == 'x' and grid[i][j] == '*'):
            clicked = True
        



def get_cnt(r, c):
    ret = 0
    for i in range(8):
        nr = r + dr[i]
        nc = c + dc[i]
        if (0 <= nr < n and 0 <= nc < n and grid[nr][nc] == '*'):
            ret += 1
    return ret


for i in range(n):
    row = input_grid[i]
    for j in range(n):
        c = row[j]
        if clicked and grid[i][j] =='*':
            print('*', end="")
        elif c == 'x':
            print(get_cnt(i, j),end="")
        elif c =='.':
            print('.', end="")
    print()