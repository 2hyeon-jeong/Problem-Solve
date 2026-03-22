import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))




def solve():
    s = input().strip()
    li = []
    for c in s:
        li.append(ord(c))
    n = len(s)
    ans = [""] * n
    def recur(s, e):
        if (e <= s): return
        t = li[s:e].index(min(li[s:e]))
        i = t + s
        ans[i] = chr(li[i])
        print("".join(ans))
        recur(i + 1, e)
        recur(s, i)
    recur(0, n)

if __name__ == '__main__':
    solve()