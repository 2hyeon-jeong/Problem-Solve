import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    arr = li()
    dp = [1] * n
    for i in range(n):
        for j in range(i+1):
            if arr[i] > arr[j]:
                dp[i] = max(dp[i], dp[j] + 1)
    print(dp[n-1])

if __name__ == '__main__':
    solve()