#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    int n; cin >> n;
    vector<map<ll, ll>> G;
    vector<vector<ll>> vs;
    vector<ll> pos;
    vector<ll> ans;
    G.resize(n+1);
    vs.resize(n+1);
    pos.resize(n+1);
    pos[0] = 0;
    int node_counter = 1; 

    for (int i = 1; i <= n; ++i) {
        int p, y; 
        cin >> p >> y;

        int u = pos[p]; 

        if (G[u].find(y) == G[u].end()) {
            G[u][y] = node_counter;
            node_counter++;
        }

        int v = G[u][y];
        
        pos[i] = v;
        vs[v].push_back(i);
    }

    function<void(int)> dfs = [&] (int i) -> void {
        for (int k : vs[i]) ans.push_back(k);
        for (auto& edge : G[i]) {
            dfs(edge.second);
        }
    };

    dfs(0);

    for (int k : ans) cout << k << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}