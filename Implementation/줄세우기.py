import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve(k):
    n = 20
    students = li()[1:]
    ans = []
    res = 0
    for s in students:
        pos = -1
        for i in range(len(ans)):
            if (s < ans[i]):
                pos = i
                break
        if (pos == -1):
            ans.append(s)
        else:
            sz = len(ans)
            res += (sz - pos)
            ans = ans[:pos] + [s] + ans[pos:]
    print(k ,res)


    

if __name__ == '__main__':
    tc = int(input())
    for i in range(tc):
        solve(i + 1)