import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    files = li()
    pref = [0] * (n+1)
    for i in range(n):
        pref[i+1] = pref[i] + files[i]
    dp = [[(1<<31)] * (n+1) for _ in range(n+1)]
    for i in range(1, n+1):
        dp[i][i] = 0
    
    for l in range(1, n+1):
        for s in range(1, n+1):
            e = s + l - 1
            if e > n: continue
            for k in range(s, e):
                dp[s][e] = min(dp[s][e], dp[s][k] + dp[k+1][e] + pref[e] - pref[s-1])
    print(dp[1][n])

if __name__ == '__main__':
    tc = int(input())
    for _ in range(tc):
        solve()