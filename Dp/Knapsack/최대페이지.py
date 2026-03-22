import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n, m = mi()
    arr = [li() for _ in range(m)]
    dp = [[0] * (n+1) for _ in range(m+1)]
    for i in range(1, m+1):
        for j in range(n+1):
            t, v = arr[i-1][0], arr[i-1][1]
            if j < t:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-t] + v)
    print(max(dp[m]))

if __name__ == '__main__':
    solve()