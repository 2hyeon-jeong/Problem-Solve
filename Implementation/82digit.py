import sys
import math
from collections import deque, Counter
from heapq import heapify, heappush, heappop
from bisect import bisect_left, bisect_right

sys.setrecursionlimit(10**6)

input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    x = (input())
    n = int(x, 8)
    print(bin(n)[2:])
    # res = []
    # while n > 0:
    #     res.append(str(n&1))
    #     n = n >> 1
    # print("".join(res[::-1]))


if __name__ == '__main__':
    solve()