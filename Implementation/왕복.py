import sys
input = sys.stdin.readline

n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(reversed(a))
prefix_a = [0] * (n+1)
prefix_b = [0] * (n+1)
for i in range(n):
    prefix_a[i+1] = prefix_a[i] + a[i]
    prefix_b[i+1] = prefix_b[i] + b[i]

t = k // prefix_a[n]
if (t % 2 == 0):
    k = k % prefix_a[n]
    for i in range(n+1):
        if (k < prefix_a[i]):
            print(i)
            break
        elif (k == prefix_a[i]):
            print(i + 1)
            break

else:
    k = k % prefix_a[n]
    for i in range(n+1):
        if (k < prefix_b[i]):
            print(n - i + 1)
            break
        elif (k == prefix_b[i]):
            print(n - i)
            break

