import sys
input = sys.stdin.readline

s = input().strip()
i = 0
sub = []
while (i < len(s)):
    c = s[i]
    
    if c == "<":
        if sub:
            sub.reverse()
            for t in sub: print(t, end="")
            sub.clear()
        temp = c
        while (temp  != ">"):
            print(temp, end="")
            i += 1
            temp = s[i]
        print(s[i], end="")
    
    elif c == " ":
        sub.reverse()
        for t in sub: print(t, end="")
        print(" ", end="")
        sub.clear()
    else:
        sub.append(c)
    
    i += 1

if sub:
    sub.reverse()
    for c in sub:
        print(c, end="")