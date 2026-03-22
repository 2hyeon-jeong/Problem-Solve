import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n, t = mi()
    arr = [li() for _ in range(n)]
    # dp[i][j] -> i번째 단원 까지 봤을 때 j시간 남았을 때의 획득할 수 있는 최대 점수
    dp = [[0] * (t+1) for _ in range(n+1)]
    for i in range(1, n+1):
        for j in range(t+1):
            k, s = arr[i-1][0], arr[i-1][1]
            # 시간이 없어서 공부하지 못할 경우
            if (j < k):
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-k] + s)
    print(max(dp[n]))

if __name__ == '__main__':
    solve()