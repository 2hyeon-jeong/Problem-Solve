import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n, k = mi()
    items = []
    dp = [[0] * (k+1) for _ in range(n+1)]
    for _ in range(n):
        w, v = mi()
        items.append((w, v))
    
    for i in range(1, n+1):
        w, v = items[i-1]
        for j in range(k+1):
            if j < w:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v)
    print(dp[n][k])



if __name__ == '__main__':
    solve()