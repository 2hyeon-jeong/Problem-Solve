import sys
input = sys.stdin.readline

grid = []
pos = dict()
checked_row = [0] * 5
checked_col = [0] * 5
checked_diag1 = 0
checked_diag2 = 0
for _ in range(5):
    grid.append(list(map(int, input().split())))

for i in range(5):
    for j in range(5):
        pos[grid[i][j]] = (i, j)

i = 0
flag = False
for _ in range(5):
    temp = list(map(int, input().split()))
    if flag: continue
    for t in temp:
        if flag: break
        i += 1
        r, c = pos[t]
        if (r == c): 
            checked_diag1 += 1
        if (r + c == 4):
            checked_diag2 += 1
        checked_col[c] += 1
        checked_row[r] += 1

        binggo = 0
        if checked_diag1 == 5:
            binggo += 1
        if checked_diag2 == 5:
            binggo += 1
        for k in range(5):
            if (checked_col[k] == 5): binggo += 1
            if (checked_row[k] == 5): binggo += 1
        if binggo >= 3:
            print(i)
            flag = True

