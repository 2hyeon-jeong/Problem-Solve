import sys
from collections import deque
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    p = [0] + li()
    adj = [[] for _ in range(n+1)]
    for i in range(1, n+1):
        adj[i] = li()[1:]
    INF = (1<<63)
    ans = INF

    for i in range(1, (1 << n) - 1):
        lsb = (i & -i).bit_length()
        lsb0 = (~i & (i + 1)).bit_length()
        v = [0] * (n+1)
        q = deque()
        q.append(lsb)
        q.append(lsb0)
        v[lsb] = 1
        v[lsb0] = -1
        while q:
            cur = q.popleft()
            for next in adj[cur]:
                cur_color = (i >> (cur - 1)) & 1
                next_color = (i >> (next - 1)) & 1 
                if v[next] or cur_color != next_color: continue
                q.append(next)
                if cur_color == 0:
                    v[next] = -1
                else:
                    v[next] = 1
        t = 0 
        ok = 1
        for k in range(1, n+1):
            if v[k] == 0: 
                ok = 0
                break
            t += v[k] * p[k]
        if ok:
            ans = min(ans, abs(t))
    if ans == INF: print(-1)
    else: print(ans)
if __name__ == '__main__':
    solve()