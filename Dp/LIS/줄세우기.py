import sys
from bisect import bisect_left
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    arr = []
    for _ in range(n): arr.append(int(input()))
    lis = [arr[0]]
    for i in range(1, n):
        idx = bisect_left(lis, arr[i])
        if idx == len(lis): lis.append(arr[i])
        else: lis[idx] = arr[i]
    print(n - len(lis))
if __name__ == '__main__':
    solve()