import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n, m = mi()
    ans = []
    check = set()
    def dfs():
        if len(ans) == m:
            print(*ans)
            return
        for i in range(1, n + 1):
            if i in check: continue
            check.add(i)
            ans.append(i)
            dfs()
            ans.pop()
            check.remove(i)
    dfs()
            


if __name__ == '__main__':
    solve()