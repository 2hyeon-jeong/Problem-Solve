import sys
input = sys.stdin.readline

dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]

def solve():
    n, d = map(int, input().split())
    grid = []
    for _ in range(n):
        grid.append(list(map(int, input().split())))
    d = (d // 45) % 8
    def rotate():
        ret = [row[:] for row in grid]
        for i in range(n//2):
            t = n//2 - i
            r, c = (i, i)
            for dr, dc in dir:
                for j in range(2):
                    nr = r + dr * t
                    nc = c + dc * t
                    ret[nr][nc] = grid[r][c]
                    r, c = nr, nc
        return ret
    
    for _ in range(d):
        grid = rotate()
    
    for g in grid:
        print(*g)


if __name__ == "__main__":
    tc = int(input())
    for _ in range(tc):
        solve()