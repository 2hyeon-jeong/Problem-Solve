import sys
from bisect import bisect_left
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    arr = li()
    dp = [arr[0]]
    for i in range(1, n):
        if dp[-1] < arr[i]: dp.append(arr[i])
        else:
            idx = bisect_left(dp, arr[i])
            dp[idx] = arr[i]
    print(len(dp))

if __name__ == '__main__':
    solve()