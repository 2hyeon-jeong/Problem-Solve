import sys
from collections import deque
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    stones = li()
    s = int(input())
    v = [0] * n
    q = deque()
    q.append(s-1)
    v[s-1] = 1
    while(q):
        cur = q.popleft()
        step = stones[cur]
        for i in [-step, step]:
            next = cur + i
            if 0 <= next < n and not v[next]:
                v[next] = 1
                q.append(next)
    print(sum(v))
    a = list()
    a.cl
if __name__ == '__main__':
    solve()