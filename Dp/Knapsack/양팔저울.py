import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    w = li() + [0]
    m = int(input())
    marble = li()
    dp = [[0] * 40001 for _ in range(n+1)]
    def recur(i, diff):
        if i > n or dp[i][diff]: return
        dp[i][diff] = 1
        recur(i+1, diff + w[i])
        recur(i+1, abs(diff - w[i]))
        recur(i+1, diff)
    recur(0, 0)
    for i in marble:
        if dp[n][i]: print("Y", end=" ")
        else: print("N", end=" ")

if __name__ == '__main__':
    solve()