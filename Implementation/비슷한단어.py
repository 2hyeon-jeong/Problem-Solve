import sys
from collections import defaultdict
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    cnt = []
    ans = 0
    for _ in range(n):
        s = input().strip()
        d = defaultdict(int)
        for c in s:
            d[c] += 1
        cnt.append(d)
    
    cur = cnt[0]
    for j in range(1, n):
        minus = 0
        plus = 0
        next = cnt[j]
        temp = defaultdict(int)
        for k in cur:
            temp[k] = max(temp[k], cur[k])
        for k in next:
            temp[k] = max(temp[k], next[k])
        for k in temp:
            diff = next[k] - cur[k]
            if (diff < 0): minus -= diff
            if (diff > 0): plus += diff
        if (plus <= 1 and minus <= 1): ans += 1
    print(ans)

if __name__ == '__main__':
    solve()