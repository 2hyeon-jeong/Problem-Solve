import sys
input = sys.stdin.readline

def solve():
    n, m = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(n)]
    
    dp = [[[float('inf')] * 3 for _ in range(m)] for _ in range(n)]
    
    for c in range(m):
        for d in range(3):
            dp[0][c][d] = grid[0][c]
            
    for r in range(1, n):
        for c in range(m):
            if c > 0:
                dp[r][c][0] = min(dp[r-1][c-1][1], dp[r-1][c-1][2]) + grid[r][c]
            
            dp[r][c][1] = min(dp[r-1][c][0], dp[r-1][c][2]) + grid[r][c]
            
            if c < m - 1:
                dp[r][c][2] = min(dp[r-1][c+1][0], dp[r-1][c+1][1]) + grid[r][c]

    ans = float('inf')
    for c in range(m):
        for d in range(3):
            ans = min(ans, dp[n-1][c][d])
            
    print(ans)

if __name__ == '__main__':
    solve()