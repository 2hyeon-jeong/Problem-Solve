import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

m = 1003002

def solve():

    def is_pal(k):
        s_k = str(k)
        l = 0
        r = len(s_k) - 1
        while(l <= r):
            if (s_k[l] != s_k[r]): return False
            l += 1
            r -= 1
        return True

    n = int(input())
    arr = [0] * m
    prime = []
    for i in range(2, m):
        if (arr[i] != 0): continue
        k = 2
        while(i * k < m):
            arr[i * k] += 1
            k += 1
        prime.append(i)

    for p in prime:
        if p < n: continue
        if (is_pal(p)):
            print(p)
            break


if __name__ == '__main__':
    solve()