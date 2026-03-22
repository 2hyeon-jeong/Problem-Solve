// Problem: BOJ 1799

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

#ifndef ONLINE_JUDGE
template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << "{" << p.first << ", " << p.second << "}";
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) os << ", ";
    }
    return os << "]";
}

#define debug(...) cerr << "[DEBUG] " << #__VA_ARGS__ << ": ", DBG(__VA_ARGS__)
template<typename T> void DBG(const T& v) { cerr << v << endl; }
template<typename T, typename... Args> void DBG(const T& v, const Args&... args) { cerr << v << ", "; DBG(args...); }
#else
#define debug(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, ans1, ans2;
vector<vector<int>> board;
vector<pii> white_cells, black_cells;
int dr[] = {1, 1, -1, -1};
int dc[] = {1, -1, 1, -1};

bool check(int r, int c) {
    if (board[r][c] == 0) return false;
    for (int i = 0; i < 4; ++i) {
        int nr = r; int nc = c;
        while(1) {
            nr += dr[i];
            nc += dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) break;;
            if (board[nr][nc] == 2) return false;
        }
    }
    return true;
}

void dfs(vector<pair<int, int>>& cells, int s, int cnt, int& ans) {
    if (s == (int)cells.size()) {
        ans = max(ans, cnt);
        return;
    }

    int r = cells[s].first;
    int c = cells[s].second;

    if (check(r, c)) {
        board[r][c] = 2;
        dfs(cells, s + 1, cnt + 1, ans);
        board[r][c] = 1;
    }

    dfs(cells, s + 1, cnt, ans);
}

void solve() {
    cin >> n;
    board.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                if ((i + j) % 2 == 0) white_cells.push_back({i, j});
                else black_cells.push_back({i, j});
            }
        }
    }

    dfs(white_cells, 0, 0, ans1);
    dfs(black_cells, 0, 0, ans2);

    cout << ans1 + ans2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}