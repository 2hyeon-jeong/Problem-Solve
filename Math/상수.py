import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    a, b = input().split(" ")
    a = list(a)
    b = list(b)
    a.reverse()
    b.reverse()
    print(max(int("".join(a)), int("".join(b))))

if __name__ == '__main__':
    solve()