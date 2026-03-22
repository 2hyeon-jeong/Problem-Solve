import sys
from bisect import bisect_left
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    arr = li()
    t = []
    prev = 0
    for i in range(n):
        k = arr[i] + i
        if k <= prev:
            t.append(prev)
            continue
        t.append(k)
        prev = k
    _ = int(input())
    qs = li()
    for q in qs:
        print(bisect_left(t, q) + 1, end= " ")

if __name__ == '__main__':
    solve()