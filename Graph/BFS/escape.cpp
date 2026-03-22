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

int dr[4] = {1, 0, -1 ,0};
int dc[4] = {0, 1, 0, -1};

void solve() {
    int n, m; cin >> n >> m;
    vector<string> maps(n);
    pii d, s;
    queue<pii> w;
    vector<vector<int>> v(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        string t; cin >> t;
        maps[i] = t;
        for (int j = 0; j < m; ++j) {
            char c = t[j];
            if (c == 'D') d = {i, j};
            else if (c == 'S') s = {i, j};
            else if (c == '*') w.push({i, j});
        }
    }
    int time = 0;
    queue<pii> q;
    q.push(s);
    v[s.first][s.second] = 0;
    while(!q.empty()) {
        for (string s : maps) debug(s);
        queue<pii> temp;
        while(!w.empty()) {
            auto[wi, wj] = w.front(); w.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = wi + dr[k];
                int nc = wj + dc[k];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                // 돌이 아니면서 물이 아니면 다 먹어버리기
                if (maps[nr][nc] != 'X' && maps[nr][nc] != '*' &&  maps[nr][nc] != 'D') {
                    maps[nr][nc] = '*';
                    temp.push({nr, nc});
                }
            }
        }
        while(!temp.empty()) {w.push(temp.front()); temp.pop();}
        
        while (!q.empty()) {
            auto[i, j] = q.front(); q.pop();
            
            for (int k = 0; k < 4; ++k) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if ((maps[nr][nc] == '.' || maps[nr][nc] == 'D') && v[nr][nc] == -1) {
                    temp.push({nr, nc});
                    v[nr][nc] = v[i][j] + 1;
                    maps[i][j] = '.';
                    maps[nr][nc] = 'S';
                }
            }
        }
        q = temp;
    }
    if (v[d.first][d.second] == -1) cout << "KAKTUS" << endl;
    else cout << v[d.first][d.second] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}