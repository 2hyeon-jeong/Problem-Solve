import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n, k = mi()
    arr = [li() for _ in range(k)]
    dp = [[0] * (n+1) for _ in range(k+1)]
    for i in range(1, k+1):
        for j in range(n+1):
            v, t = arr[i-1][0], arr[i-1][1]
            if j < t:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-t] + v)
    print(max(dp[k]))
if __name__ == '__main__':
    solve()