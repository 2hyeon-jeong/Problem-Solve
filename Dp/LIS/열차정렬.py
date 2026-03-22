import sys
from collections import deque
from bisect import bisect_left
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    inc = [1] * n
    dec = [1] * n
    arr = []
    for _ in range(n): arr.append(int(input()))
    # i번째 애를 중심으로 잡았을 때 오른쪽에 있는 애들에 대해서 inc, dec를 구해야하기에
    # 왼쪽으로부터 LIS, LDS구하는 방식을 사용하기 위해 reverse
    arr.reverse()
    for i in range(n):
        for j in range(i+1):
            if arr[i] > arr[j]:
                inc[i] = max(inc[i], inc[j] + 1)

    for i in range(n):
        for j in range(i+1):
            if arr[i] < arr[j]:
                dec[i] = max(dec[i], dec[j] + 1)
    ans = 0
    for i in range(n):
        ans = max(ans, inc[i] + dec[i] - 1)
    print(ans)
if __name__ == '__main__':
    solve()