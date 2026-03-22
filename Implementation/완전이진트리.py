import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

# def solve():
#     k = int(input())
#     arr = [0] + li()
#     ans = [[] for _ in range(k)]
#     def tree(s, e, dep):
#         if (s == e): 
#             ans[dep].append(arr[s])
#         elif(s < e):
#             m = (s + e) // 2
#             ans[dep].append(arr[m])
#             tree(s, m-1, dep+1)
#             tree(m+1, e, dep+1)
#     tree(1, (1 << k) - 1, 0)
#     for a in ans:
#         print(*a)

def solve():
    k = int(input())
    arr = [0] + li()
    ans = [[] for _ in range(k)]
    for i in range(1, (1 << k)):
        dep = k - (i & (-i)).bit_length()
        ans[dep].append(arr[i])
    for a in ans:
        print(*a)

if __name__ == '__main__':
    solve()