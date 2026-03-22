import sys
input = sys.stdin.readline

n, m = map(int, input().split())
s = input().strip()
t = input().strip()
if s == t: print(0)
else:
    s_pos = []
    t_pos = []
    for i in range(n + m):
        cs = s[i]
        ct = t[i]
        if cs == "1": s_pos.append(i)
        if ct == "1": t_pos.append(i)
    total_move = 0
    for i in range(len(s_pos)):
        total_move += abs(s_pos[i] - t_pos[i])
    move_s = total_move // 2
    move_t = total_move - move_s
    print(move_s * move_s + move_t * move_t)
