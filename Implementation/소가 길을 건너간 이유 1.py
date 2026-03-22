import sys
input = sys.stdin.readline

n = int(input())
cnt = [0]*11
prev = [-1]*11
for _ in range(n):
    cow, a = map(int, input().split())
    if prev[cow] == -1:
        prev[cow] = a
        continue
    if prev[cow] != a:
        cnt[cow] += 1
        prev[cow] = a

print(sum(cnt))