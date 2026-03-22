import sys
input = sys.stdin.readline

n = int(input())
ans = 0
for _ in range(n):
    s = input().strip()
    prev = s[0]
    used = set()
    ok = True
    for cur in s[1:]:
        if (prev != cur):
            if (prev in used):
                ok = False
                break
            used.add(prev)
            prev = cur
    if (s[-1] in used):
        ok = False
    if ok: ans += 1
print(ans)