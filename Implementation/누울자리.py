import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    grid = [input().strip() for _ in range(n)]
    row = [0] * n
    col = [0] * n
    for i in range(n):
        r = grid[i].split("X")
        c = ""
        for k in range(n):
            c += grid[k][i]
        c = c.split("X")
        for t in r:
            if len(t) >= 2:
                row[i] += 1
        for t in c:
            if len(t) >= 2:
                col[i] += 1
    print(sum(row), sum(col))


if __name__ == '__main__':
    solve()