import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    L = li()
    J = li()
    # dp[i][j] -> i명의 사람을 만나면서 j의 체력을 갖을 때 최대 행복
    dp = [[0] * 101 for _ in range(n+1)]
    for i in range(1, n+1):
        loss = L[i-1]
        joy = J[i-1]
        for j in range(101):
            if (j <= loss):
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-loss] + joy)
    print(max(dp[n]))

if __name__ == '__main__':
    solve()