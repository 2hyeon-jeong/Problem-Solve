import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    wants = li()
    budget = int(input())
    mean_budget = budget // n
    k = 0
    t = -1
    wants.sort()
    for i in range(n):
        want = wants[i]
        if (want <= mean_budget):
            if (k == n - 1): k -= 1
            k += 1
            budget -= want
            mean_budget = budget // (n - k)
            t = max(t, want)
        else:
            t = max(t, mean_budget)
    print(t)

if __name__ == '__main__':
    solve()