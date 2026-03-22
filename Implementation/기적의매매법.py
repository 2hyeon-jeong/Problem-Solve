import sys
input = sys.stdin.readline

n = int(input())
prices = list(map(int, input().split()))

def bnp(n):
    i = 0
    for p in prices:
        if (n >= p):
            i = n // p
            n = n % p
    return i * prices[-1] + n

def timing(n):
    res = n
    have = 0
    for i in range(len(prices) - 3):
        p1 = prices[i]
        p2 = prices[i+1]
        p3 = prices[i+2]
        p4 = prices[i+3]
        if (p1 < p2 and p2 < p3 and p3 < p4):
            res += have * p4
            have = 0
        elif (p1 > p2 and p2 > p3 and p3 > p4):
            have += res // p4
            res %= p4
    return res + have * prices[-1]


b = bnp(n)
t = timing(n)
if (b > t): print("BNP")
elif(b == t): print("SAMESAME")
else: print("TIMING")