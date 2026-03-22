import sys
input = sys.stdin.readline

n = int(input())
days = [0] * 366
for _ in range(n):
    s, e = map(int, input().split())
    for i in range(s, e + 1):
        days[i] += 1

w = 0
h = 0
ans = 0
for i in range(1, 366):
    if days[i] == 0:
        ans += w * h
        w = 0
        h = 0
        continue
    w += 1
    h = max(h, days[i])

ans += w * h
print(ans)

