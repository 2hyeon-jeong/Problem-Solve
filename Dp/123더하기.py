import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = 100000
    MOD = 1000000009
    dp = [[0] * 4 for _ in range(n+1)]
    dp[1][1] = 1
    dp[2][2] = 1
    dp[3][3] = 1
    dp[3][1] = 1
    dp[3][2] = 1
    for i in range(4, n+1):
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD

    tc = int(input())
    for _ in range(tc):
        n = int(input())

        print((dp[n][1] + dp[n][2] + dp[n][3]) % MOD)

if __name__ == '__main__':
    solve()