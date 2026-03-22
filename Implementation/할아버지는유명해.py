import sys

input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    while 1:
        n, m = map(int, input().split())
        if (n == 0 and m == 0): break
        cnt = [0] * 10001
        for _ in range(n):
            p = list(map(int, input().split()))
            for i in p:
                cnt[i] += 1
        first = max(cnt)
        second = -1
        for i in range(1, 10001):
            if (cnt[i] == first): continue
            second = max(second, cnt[i])
        for i in range(1, 10001):
            if (cnt[i] == second): print(i, end=" ")
        print()

if __name__ == '__main__':
    solve()