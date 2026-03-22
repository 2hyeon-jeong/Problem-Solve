import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n = int(input())
    s = set()
    for _ in range(n):
        t = input().strip()
        if (t == "all"):
            s.clear()
            for i in range(1, 21):
                s.add(i)
            continue
        if (t == "empty"):
            s.clear()
            continue
        cmd, x = t.split()
        x = int(x)
        if (cmd == "add"):
            s.add(x)
        elif(cmd == "remove"):
            if x in s:
                s.remove(x)
        elif cmd == "check":
            print(int(x in s))
        elif cmd == "toggle":
            if (x in s):
                s.remove(x)
            else:
                s.add(x)
        

if __name__ == '__main__':
    solve()