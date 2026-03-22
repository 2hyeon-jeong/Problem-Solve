n = int(input())
sz = (n-1)*4+1
arr = [[" "]*sz for _ in range(sz)]
dir = [(1, 0), (0, 1), (-1, 0), (0, -1)]
for i in range(n-1, 0, -1):
    r = (n - 1 - i) * 2
    c = (n - 1 - i) * 2
    for dr, dc in dir:
        for j in range(4*i):
            arr[r][c] = '*'
            r += dr
            c += dc
arr[2*(n-1)][2*(n-1)] = "*"
for i in range(sz):
    for j in range(sz):
        print(arr[i][j], end="")
    print()
