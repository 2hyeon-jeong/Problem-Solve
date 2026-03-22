import sys
input = sys.stdin.readline

n, m = map(int, input().split())
trains = [0] * (n+1)
check = set()
upper = (1 << 20) - 1
for _ in range(m):
    cmd = list(map(int, input().split()))
    t = cmd[0]
    i = cmd[1]
    if (t == 1):    
        x = cmd[2]
        trains[i] |= (1 << (x-1))
    elif (t == 2):
        x = cmd[2]
        trains[i] = trains[i] & (~(1 << (x-1)))
    elif t == 3:
        trains[i] <<= 1
        trains[i] &= upper
    elif t == 4:
        trains[i] >>= 1

for train in trains[1:]:
    if (train in check): continue
    check.add(train)

print(len(check))

