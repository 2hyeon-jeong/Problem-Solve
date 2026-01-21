// Problem: BOJ 5052

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<map<int, int>> G;
vector<bool> is_end;


void solve() {
    int n; cin >> n;
    G.clear(); is_end.clear();
    G.resize(10000 * 10 + 1); is_end.resize(10000 * 10 + 1 ,false);
    int node_cnt = 1;
    bool ans = true;
    while(n--) {
        bool flag = true;
        string s; cin >> s;
        int cur = 0;
        for (char c : s) {
            if (is_end[cur] == true) ans = false;
            if (G[cur].find(c-'0') == G[cur].end()) {
                G[cur][c-'0'] = node_cnt++;
            }
            cur = G[cur][c-'0'];
        }
        is_end[cur] = true;
        if (!G[cur].empty()) {
            ans = false;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}