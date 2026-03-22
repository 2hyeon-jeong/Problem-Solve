import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    coins = li()
    m = int(input())
    # dp[i][j] = k -> 앞에서 부터 i개의 동전을 사용하여 j원을 만들 때의 경우의 수 = k
    dp = [[0] * (m+1) for _ in range(n+1)]
    dp[0][0] = 1
    for i in range(1, n+1):
        for j in range(m+1):
            c = coins[i-1]
            if (j < c): # 현재 c원으로 j원을 만들 수 없으니 아래서 올리기
                dp[i][j] = dp[i-1][j]
            else: 
                # 현재 동전을 쓰지 않은 경우의 수 dp[i-1][j]
                # 현재 동전을 적어도 하나를 쓴 경우의 수 dp[i][j-c]
                dp[i][j] = dp[i-1][j] + dp[i][j-c]
    print(dp[n][m])


if __name__ == '__main__':
    tc = int(input())
    for _ in range(tc):
        solve()