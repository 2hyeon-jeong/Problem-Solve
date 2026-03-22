import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    t, w = mi()
    dp = [[0] *(w+1) for _ in range(t+1)]
    for i in range(1, t+1):
        tree = int(input()) - 1
        for j in range(w+1):
            # 이전 상태가 없으니 그냥 안움직이고 받거나 안받거나
            if j == 0:
                dp[i][j] = dp[i-1][j] + (tree == 0)
            # 이전 상태가 있을 때
            else:
                #이전 위치에서 가만히 있는 경우와 이전 위치에서 움직인 경우에
                # + 현재 떨어지는 위치라면 + 1 
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + (j % 2 == tree)
    print(max(dp[t]))

if __name__ == '__main__':
    solve()