import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    dp = [0] * (1000 + 1)
    # 0 -> 상근, 1 -> 창영 win
    dp[1] = 1
    dp[2] = 0
    dp[3] = 1
    for i in range(4, n+1):
        dp[i] = int((not dp[i-1]) or (not dp[i-3]))
    if(dp[n]):
        print("CY")
    else:
        print("SK")


if __name__ == '__main__':
    solve()
