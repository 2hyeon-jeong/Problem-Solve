import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n, k = mi()
    s = input().strip()
    eat = [False] * n
    for i in range(n):
        if (s[i] == "H"): continue
        for r in range(-k, k+1):
            idx = i + r
            if (idx < 0 or idx >= n): continue
            if (s[idx] == "H" and not eat[idx]):
                eat[idx] = True
                break
    print(sum(eat))

if __name__ == '__main__':
    solve()