import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    arr = li()
    dp = [1] * n
    parent = [-1] * n
    for i in range(n):
        for j in range(i+1):
            if arr[i] > arr[j]:
                if dp[i] < dp[j] + 1:
                    parent[i] = j
                dp[i] = max(dp[i], dp[j] + 1)
    m = max(dp)
    print(m)
    idx = dp.index(m)
    # 최대 유량에서 뒤로 올라가는 듯이 이것도 마찬가지
    ans = []
    while idx != -1:
        ans.append(arr[idx])
        idx = parent[idx]
    ans.reverse()
    print(*ans)


if __name__ == '__main__':
    solve()