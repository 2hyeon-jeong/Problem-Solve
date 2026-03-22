import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    t, w = mi()
    # dp[i][j] -> i번째 자두까지 봤을 때 j번 움직여서 받은 최대 자두 개수
    # subproblem: 움직여서 받기, 안 움직이고 받기, 안움직이고 안받기
    dp = [[0] * (w+1) for _ in range(t+1)]
    for i in range(1, t+1):
        tree = int(input()) - 1
        for j in range(w+1):
            # 떨어지는 곳이니 원래 있던 위치를 고수하는 경우와 다른 위치에 있던애가 움직여서 받으러 오기
            if j % 2 == tree: 
                # 근데 이전 상태에서 움직인 적이 없으면 그냥 안움직이고 받기밖에 없음
                if j == 0:
                    dp[i][j] = dp[i-1][j] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + 1
            else:
                # 안떨어지는 곳을 굳이 찾아올 필요가 없으니 그냥 안움직이고 안받기로만 갱신
                dp[i][j] = dp[i-1][j]
    print(max(dp[t]))


if __name__ == '__main__':
    solve()