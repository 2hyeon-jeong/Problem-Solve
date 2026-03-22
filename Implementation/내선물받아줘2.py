import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    s = input().strip()
    ans = 0
    for i in range(n-1):
        if s[i] == 'E' and s[i+1] == 'W': ans += 1
    print(ans)
if __name__ == '__main__':
    solve()