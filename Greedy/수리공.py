import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n, l = mi()
    arr = li()
    arr.sort()
    m = max(arr)
    i = 0
    ans = 0
    while i < n:
        cur = arr[i]
        j = 1
        while i + j < n:
            if cur + (l - 1) < arr[i + j]: break
            j += 1
        i += j
        ans += 1
    print(ans)

if __name__ == '__main__':
    solve()