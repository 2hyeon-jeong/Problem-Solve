import sys
input = sys.stdin.readline

result = [[]]

def tran(c):
    if c == "q": return 0
    if c == "u": return 1
    if c == "a": return 2
    if c == "c": return 3
    if c == "k": return 4
    else: return -1

def solve(s):
    for c in s[1:]:
        t = tran(c)
        is_in = False
        if t == -1: return False
        while not is_in:
            for r in result:
                if (r[-1] + 1) % 5 == t:
                    r.append(t)
                    is_in = True
                    break
            
            if not is_in:
                if t == 0:
                    result.append([0])
                    is_in = True
                else:
                    return False
    return True

s = input()
is_duck = True
if s[0] != 'q': is_duck = False
else:
    result[0].append(0)
    is_duck = solve(s.strip())

flag = True
for r in result:
    if not r or r[-1] != 4: flag = False
if is_duck and flag:
    print(len(result))

else: print(-1)