import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    if n % 3 == 1: print("U")
    elif n % 3 == 2: print("O")
    else: print("S")

if __name__ == '__main__':
    solve()