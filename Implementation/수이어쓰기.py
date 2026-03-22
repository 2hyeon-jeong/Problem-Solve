import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    s = list(map(int, input().strip()))
    
    prev = s[0]
    if prev == 0:
        prev = 10
        
    i = 1
    
    while i < len(s):
        k = prev
        while True:
            k += 1
            s_k = str(k)
            
            temp_i = i
            for char in s_k:
                if temp_i < len(s) and char == str(s[temp_i]):
                    temp_i += 1
            
            if temp_i > i:
                prev = k 
                i = temp_i
                break         
    print(prev)
    
if __name__ == '__main__':
    solve()