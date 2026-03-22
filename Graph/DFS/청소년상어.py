import sys
from copy import deepcopy
input = sys.stdin.readline

mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

dir = [(-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1)]

def get_pos(t, board):
    for i in range(4):
        for j in range(4):
            if board[i][j][0] == t and board[i][j][2]:
                return (i, j)
    return (-1, -1)
    
def move(board, shark_pos):
    for i in range(1, 16 + 1):
        r, c = get_pos(i, board)
        if (r, c) == shark_pos or (r, c) == (-1, -1): continue
        d = board[r][c][1]
        for di in range(8):
            board[r][c][1] = (d + di) % 8
            dr, dc = dir[board[r][c][1]]
            nr, nc = r + dr, c + dc
            
            if (0 <= nr < 4 and 0 <= nc < 4 and (nr, nc) != shark_pos):
                board[r][c], board[nr][nc] = board[nr][nc], board[r][c]
                break

def backtracking(board, shark_pos):
    r, c = shark_pos
    board[r][c][2] = False
    move(board, shark_pos)    
    d = board[r][c][1]
    reachable = []
    ret = board[r][c][0]
    for i in range(1, 5):
        dr, dc = dir[d]
        nr, nc = r + dr * i, c + dc * i
        if (0 <= nr < 4 and 0 <= nc < 4 and board[nr][nc][2]):
            reachable.append((nr, nc))
    m = 0
    if not reachable: return ret
    else:
        for rr, cc in reachable:
            m = max(m, backtracking(deepcopy(board), (rr, cc)))
    return ret + m


def solve():
    r, c = 4, 4
    board = []
    for _ in range(r):
        temp = li()
        f = temp[::2]
        d = temp[1::2]
        t = []
        for i in range(c):
            t.append([f[i], d[i] - 1, True])
        board.append(t)
    s = (0, 0)
    ans = backtracking(deepcopy(board), s)
    print(ans)



if __name__ == '__main__':
    solve()