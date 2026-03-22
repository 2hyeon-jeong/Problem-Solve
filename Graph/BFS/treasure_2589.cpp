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

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int bfs(int i, int j, const vector<string>& maps) {
    int ret = 0;
    int n = sz(maps);
    int m = sz(maps[0]);
    queue<pii> q;
    vector<vector<int>> v(n, vector<int>(m, -1));
    q.push({i, j});
    v[i][j] = 0;
    while(!q.empty()) {
        auto[r, c] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (maps[nr][nc] == 'W' || v[nr][nc] != -1) continue;
            q.push({nr, nc});
            v[nr][nc] = v[r][c] + 1;
            ret = max(ret, v[nr][nc]);
        }
    }
    return ret;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<string> maps(n);
    int ans = -1;
    for (int i = 0; i < n; ++i) cin >> maps[i];
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maps[i][j] == 'L') {
                ans = max(ans, bfs(i, j, maps));
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}