import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    a, b = map(str, input().split())
    ta = int(a, 2)
    tb = int(b, 2)
    temp = ta + tb
    ans = []
    if (temp == 0):
        print(0)
        return
    while (temp > 0):
        ans.append(str(temp & 1))
        temp >>= 1
    ans.reverse()
    print("".join(ans))


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()