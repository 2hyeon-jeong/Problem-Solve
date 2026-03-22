import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    mat = [li() for _ in range(n)]
    dp = [[(1 << 63)] *(n+1) for _ in range(n+1)]
    for i in range(n):
        dp[i][i] = 0
    for len in range(1, n):
        for s in range(n):
            e = s + len
            if (e >= n): break
            for k in range(s, e):
                # 길이가 짧을 때 부터 반복을 돌렸기에 길이가 짧은 부분에 대한 데이터가 이미 존재하기에
                # 중간 값 k로 분할하여서 최소값을 계속 갱신한다.
                dp[s][e] = min(dp[s][e],
                               dp[s][k] + dp[k+1][e] + mat[s][0] * mat[k][1] * mat[e][1])
    print(dp[0][n-1])

if __name__ == '__main__':
    solve()