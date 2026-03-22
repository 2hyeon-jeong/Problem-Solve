import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    k = int(input())
    A = [0] * (k+1)
    B = [0] * (k+1)
    A[0] = 1
    for i in range(1, k+1):
        A[i] = B[i-1]
        B[i] = B[i-1] + A[i-1]
    print(A[k], B[k])


if __name__ == '__main__':
    solve()