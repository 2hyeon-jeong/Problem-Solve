import sys
from bisect import bisect_left
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    arr = li()
    lis = [arr[0]]
    for i in range(1, n):
        if lis[-1] < arr[i]: lis.append(arr[i])
        else:
            idx = bisect_left(lis, arr[i])
            lis[idx] = arr[i]
    print(n - len(lis))


if __name__ == '__main__':
    solve()