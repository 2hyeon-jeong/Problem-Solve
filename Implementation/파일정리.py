import sys
from collections import defaultdict
input = sys.stdin.readline

n = int(input())
d = defaultdict(int)
for _ in range(n):
    s = input().strip()
    l = s.split(".")
    d[l[1]] += 1

temp = sorted(d)
for key in temp:
    print(key, d[key])