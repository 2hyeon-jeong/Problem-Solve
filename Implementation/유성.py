import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    r, c = map(int, input().split())
    grid = []
    for i in range(r):
        s = input().strip()
        temp = []
        for char in s:
            temp.append(char)
        grid.append(temp)
    d = 1e9
    for i in range(c):
        ground = 0
        for j in range(r-1, -1, -1):
            if (grid[j][i] == "#"): ground = j
            elif grid[j][i] == "X":
                d = min(d, ground - j - 1)

    for i in range(r-1, -1, -1):
        for j in range(c):
            if (grid[i][j] == 'X'):
                grid[i + d][j], grid[i][j] = grid[i][j], grid[i + d][j]
    
    for g in grid:
        print("".join(g))

if __name__ == '__main__':
    solve()