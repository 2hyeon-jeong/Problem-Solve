import sys
from bisect import bisect_left
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    arr = li()
    dp = [0] * (n+1)
    for i in range(n):
        v = arr[i]
        dp[v] = dp[v-1] + 1
    print(n - max(dp))
if __name__ == '__main__':
    solve()