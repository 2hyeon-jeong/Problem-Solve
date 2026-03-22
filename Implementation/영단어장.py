import sys
from collections import defaultdict
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))



def solve():
    n, m = mi()
    d = defaultdict(int)
    for _ in range(n):
        s = input().strip()
        if (len(s) < m): continue
        d[s] += 1
    arr = []
    for key in d:
        t = (d[key], key)
        arr.append(t)
    
    arr.sort(key=lambda x: (-x[0], -len(x[1]), x[1]))
    for i, j in arr:
        print(j)

if __name__ == '__main__':
    solve()