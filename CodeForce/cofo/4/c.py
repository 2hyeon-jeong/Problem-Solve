import sys
input = sys.stdin.readline

def solve():
    n, k = map(int, input().split())
    s = []
    col = list(set())
    for _ in range(k):
        s.append(input().strip())
    for i in range(n):
        temp = []
        for j in range(k):
            temp.append(s[j][i])
        col.append(set(temp))
    
    for step in range(1, n+1):
        flag = True
        ans = []
        if (n % step != 0): continue
        for start in range(step):
            t = col[start]
            for r in range(n // step):
                t = t & col[start + r * step]
                if not t:
                    flag = False
                    break
            
            if not flag: break

            ans.append(list(t)[0])
        
        if flag:
            print(("".join(ans)) * (n // step))
            return

if __name__ == "__main__":
    tc = int(input())
    for _ in range(tc):
        solve()