import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    m = 10001
    fivo = [0] * m
    fivo[0] = 0
    fivo[1] = 1
    for i in range(2, m):
        fivo[i] = fivo[i-1] + fivo[i-2]
    n = int(input())
    print(fivo[n])

if __name__ == '__main__':
    solve()