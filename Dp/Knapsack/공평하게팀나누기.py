import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    w = [int(input()) for _ in range(n)]
    sw = sum(w)
    m = sw / n
    dp = [[-1] * (sw+1) for _ in range(n//2)]
    for s in range(n - n//2):
        for i in range(1, n//2 + 1):
            for j in range(sw+1):
                
                

if __name__ == '__main__':
    solve()