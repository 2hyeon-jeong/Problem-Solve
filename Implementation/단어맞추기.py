import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

# 1 4 2 3 5 -> 1 4 2 5 3
# 1 4 5 3 2 -> 1 5 4 3 2
# 증가 하다가 감소 하면 체킹 했다가 마지막 감소에서 스왑 근데 처음 한번 증가 후 감소만 하면 앞자리 바꾸기
# 감소만 하면 그냥 출력
# 1 5 4 3 2 -> 2 1 3 4 5
def solve():
    s = input().strip()
    t = []
    for c in s:
        t.append(ord(c) - ord("A"))
    def get_next_word(word_list):
        n = len(word_list)
        
        i = n - 1
        while i > 0 and word_list[i-1] >= word_list[i]:
            i -= 1
            
        if i <= 0:
            return False 
        
        j = n - 1
        while word_list[j] <= word_list[i-1]:
            j -= 1
            
        word_list[i-1], word_list[j] = word_list[j], word_list[i-1]
        word_list[i:] = reversed(word_list[i:])
        
        return True
    if get_next_word(t):
        for i in t:
            print(chr(i + ord("A")), end="")
        print()
    else:
        print(s)




if __name__ == '__main__':
    tc = int(input())
    for _ in range(tc):
        solve()