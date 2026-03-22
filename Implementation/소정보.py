import sys
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

def solve():
    n, _ = mi()
    cows = li()
    points = [1] * n
    for i in range(n):
        for j in range(4):
            points[i] *= cows[(i+j) % n]
        
    s = sum(points)
    queries = li()
    # 0을 포함한 것 -> n-3, n-2, n-1, 0
    # q를 포함한 것 -> q-3, q-2, q-1, q
    for q in queries:
        q -= 1
        for i in range(4):
            points[(q - i) % n] *= -1
            s += 2 * points[(q - i) % n]
        print(s)

if __name__ == '__main__':
    solve()