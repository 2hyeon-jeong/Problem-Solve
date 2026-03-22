import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def print_ans(s, t):
    for i in range(len(s)):
        c = s[i]
        if (c != t):
            print(c,end="")
        else:
            print(f"[{c}]", end="")
            print(s[i+1:])
            break

def solve():
    n = int(input())
    s = set()
    for _ in range(n):
        st = input().strip()
        arr = list(st.split(" "))
        ok = False
        for t in arr:
            if (t[0] not in s):
                s.add(t[0].upper())
                s.add(t[0].lower())
                ok = True
                print_ans(st, t[0])
                break
        
        if (not ok):
            for t in arr:
                for c in t:
                    if (c not in s):
                        s.add(c.upper())
                        s.add(c.lower())
                        ok = True
                        print_ans(st, c)
                        break
                if ok: break
        if not ok:
            print(st)

if __name__ == '__main__':
    solve()