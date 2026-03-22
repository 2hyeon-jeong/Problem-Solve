import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    k = int(input())
    t = format(k+1, 'b')
    for c in t[1:]:
        if (c == "0"):
            print("4", end="")
        else:
            print("7", end="")

if __name__ == '__main__':
    solve()