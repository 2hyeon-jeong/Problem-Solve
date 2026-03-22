import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def is_good(s):
    n = len(s)
    if n == 2:
        return s[0] != s[1]
    for l in range(1, n//2 + 1):
        idx = 0
        for i in range(n):
            prev = s[i:i + l]
            cur = s[i+l: i + l + l]
            if prev == cur: return False
    
    return True

def solve():
    n = int(input())
    if n == 1:
        print(1)
        return
    ans = ["1"]
    ok = False
    def bt():
        nonlocal ok
        if ok: return
        if not is_good(ans): return
        if len(ans) == n:
            ok = True
            print("".join(ans))
            return
        ans.append("1")
        bt()
        ans.pop()
        ans.append("2")
        bt()
        ans.pop()
        ans.append("3")
        bt()
        ans.pop()
    bt()

if __name__ == '__main__':
    solve()