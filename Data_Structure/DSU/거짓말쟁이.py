import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

parent = []

def find(x):
    global parent
    if parent[x] !=  x: parent[x] = find(parent[x])
    return parent[x]

def union(x, y):
    global parent
    px = find(x)
    py = find(y)
    if px != py:
        parent[py] = px

def solve():
    global parent
    n, m = mi()
    know = li()[1:]
    parent = [i for i in range(n+1)]
    qs = []
    ans = 0
    for _ in range(m):
        t = li()[1:]
        qs.append(t)
        for i in range(1, len(t)):
            union(t[0], t[i])
    s = {find(x) for x in know}
    for q in qs:
        if find(q[0]) not in s:
            ans += 1
    print(ans)
if __name__ == '__main__':
    solve()