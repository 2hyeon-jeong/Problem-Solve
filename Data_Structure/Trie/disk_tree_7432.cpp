// Problem: BOJ 7432

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<map<string, int>> G;

void dfs(int node, int depth) {
    for (auto& edge : G[node]) {
        for (int i = 0; i < depth; ++i) cout << " ";
        cout << edge.first << endl;
        dfs(edge.second, depth + 1);
    }
}

void solve() {
    int n; cin >> n;
    G.resize(500 * 80 + 1);
    int node_cnt = 1;
    while(n--) {
        int cur = 0;
        string s; cin >> s;
        vector<string> v;
        stringstream ss(s);
        string seg;
        while(getline(ss, seg, '\\')) {
            v.push_back(seg);
        }
        for (int i = 0; i < sz(v); ++i) {
            if (G[cur].find(v[i]) == G[cur].end()) {
                G[cur][v[i]] = node_cnt++;
            }
            cur = G[cur][v[i]];
        }
    }
    dfs(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}