import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    k = int(input())
    n = int(input())
    ans = ['*'] * (k - 1)
    target = [-1] * k
    t = input().strip()
    for i in range(k):
        target[i] = ord(t[i]) - ord('A')
    ladder = [input().strip() for _ in range(n)]

    for i in range(k):
        down = i
        up = target[i]
        for r in range(n):
            if (ladder[r][0] == "?"): break
            left = up - 1
            right = up
            if (0 <= left and ladder[r][left] == '-'):
                up -= 1
            elif (right < k - 1 and ladder[r][right] == '-'):
                up += 1
        for r in range(n-1, -1, -1):
            if (ladder[r][0] == "?"): break
            left = down - 1
            right = down
            if (0 <= left and ladder[r][left] == '-'):
                down -= 1
            elif (right < k - 1 and ladder[r][right] == '-'):
                down += 1
        if (up == down): ans[up - 1] = '*'
        elif (up - down == 1):
            ans[down] = '-'
        elif (up - down == -1):
            ans[up] = '-'
        else:
            print("x" * (k-1))
            return 

    print("".join(ans))



if __name__ == '__main__':
    solve()