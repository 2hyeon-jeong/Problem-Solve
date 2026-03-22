import sys
input = sys.stdin.readline

left = [['q', 'w', 'e', 'r', 't'],
         ['a', 's','d', 'f','g'],
         ['z','x','c','v']]

right = [['0', 'y', 'u', 'i', 'o', 'p'], 
         ['0', 'h', 'j','k', 'l'],
         ['b','n','m']]

dl = dict()
dr = dict()
for i in range(3):
    for j in range(len(left[i])):
        dl[left[i][j]] = (i, j)

for i in range(3):
    for j in range(len(right[i])):
        dr[right[i][j]] = (i, j)

l, r = input().split()
target = input().strip()
ans = 0
for t in target:
    if (t in dl):
        cur_r, cur_c = dl[l]
        nxt_r, nxt_c = dl[t]
        move = abs(cur_r - nxt_r) + abs(cur_c - nxt_c)
        ans += move + 1
        l = t
    else:
        cur_r, cur_c = dr[r]
        nxt_r, nxt_c = dr[t]
        move = abs(cur_r - nxt_r) + abs(cur_c - nxt_c)
        ans += move + 1
        r = t
print(ans)

