import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    MOD = 9901
    dp = [[0] * 3 for _ in range(n+1)]
    dp[1][0] = 1
    dp[1][1] = 1
    dp[1][2] = 1
    for i in range(2, n+1):
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD
        dp[i][2] = (dp[i-1][0] + dp[i-1][2]) % MOD
        dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][0]) % MOD
    print((dp[n][1] + dp[n][2] + dp[n][0]) % MOD)
if __name__ == '__main__':
    solve()