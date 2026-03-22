import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))
ans = ""
def dfs(maps, n):
    global ans
    t = 0
    for i in maps:
        for j in i:
            t += int(j)
    if t == 0:
        ans += "0"
        return 
    elif t == n*n:
        ans += "1"
        return 
    else:
        ans += "("
        half = n // 2
        sub1 = [row[:half] for row in maps[:half]]
        sub2 = [row[half:] for row in maps[:half]]
        sub3 = [row[:half] for row in maps[half:]]
        sub4 = [row[half:] for row in maps[half:]]
        dfs(sub1, n//2)
        dfs(sub2, n//2)
        dfs(sub3, n//2)
        dfs(sub4, n//2)
        ans += ")"

def solve():
    n = int(input())
    maps = [input().strip() for _ in range(n)]
    dfs(maps, n)
    print(ans)

if __name__ == '__main__':
    solve()