// Problem: BOJ 14725

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void dfs(vector<map<string, int>>& G, int node, int depth) {
    for (auto& edge : G[node]) {
        string s = edge.first;
        for (int i = 0; i < depth; ++i) cout << "--" << "";
        cout << s << endl;
        dfs(G, edge.second, depth + 1);
    }
}

void solve() {
    vector<map<string,int>> G;
    int n; cin >> n;
    G.resize(15001);
    int node_cnt = 1;
    while(n--) {
        int k; cin >> k;
        int cur = 0;

        for (int i = 0; i < k; ++i) {
            string s; cin >> s;
            if (G[cur].find(s) == G[cur].end()) {
                G[cur][s] = node_cnt++;
            }
            cur = G[cur][s];
        }
    }
    dfs(G, 0, 0);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}