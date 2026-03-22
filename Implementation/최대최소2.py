import sys
input = sys.stdin.readline

tc = int(input())
for _ in range(tc):
    n = int(input())
    nums = list(map(int, input().split()))
    print(min(nums), max(nums))