import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

# 0 -1 -1 -1 -1 -1
# -1 1 -1 -1 -1 -1
# -1 1 2 -1 -1 -1
# -1 -1 -1 1 -1 3
# -1 -1 1 -1 -1 2

def solve():
    n, k = mi()
    cafeins = li()
    # dp[i][j] -> i개의 커피를 봤을 때 j만큼의 카페인을 섭취할 때의 최소 커피수.
    dp = [[-1] * (k+1) for _ in range(n+1)]
    dp[0][0] = 0
    for i in range(1, n+1):
        c = cafeins[i-1]
        for j in range(k+1):
            not_take = dp[i - 1][j]
            take = -1

            if j >= c and dp[i - 1][j - c] != -1:
                take = dp[i - 1][j - c] + 1

            if not_take == -1 and take == -1:
                dp[i][j] = -1
            elif not_take == -1:
                dp[i][j] = take
            elif take == -1:
                dp[i][j] = not_take
            else:
                dp[i][j] = min(not_take, take)
    print(dp[n][k])


if __name__ == '__main__':
    solve()