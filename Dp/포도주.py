import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    dp = [0] * (n+1)
    drink = [0]
    for _ in range(n): drink.append(int(input()))
    dp[1] = drink[1]
    dp[2] = dp[1] + drink[2]
    for i in range(3, n+1):
        dp[i] = max(dp[i-1], dp[i-2] + drink[i], dp[i-3] + drink[i] + drink[i-1])
    print(dp[n])

if __name__ == '__main__':
    solve()