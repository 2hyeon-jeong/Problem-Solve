import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def get_n(k):
    ret = 0
    while(k > 0):
        ret += k % 10
        k //= 10
    return ret

def solve():
    n = 10001
    cnt = [0] * n
    for i in range(1, n):
        k = get_n(i) + i
        while(k < n):
            cnt[k] += 1
            k += get_n(k)
    for i in range(1, n):
        if (cnt[i] == 0):
            print(i)

if __name__ == '__main__':
    solve()