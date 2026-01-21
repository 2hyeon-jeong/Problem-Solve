// Problem: BOJ 5670

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
int ans;

void dfs(int node, int cnt) {
    int flag = 0;
    if (node != 0 && (sz(G[node]) >= 2 || is_end[node] == true)) flag = 1;
    if (is_end[node]) ans += cnt;
    for (auto& edge : G[node]) {
        int s = edge.first;
        int next = edge.second;
        dfs(next, cnt + flag);
    }
}

void solve() {
    int n;
    while(cin >> n) {
        ans = 0;
        G.clear(); is_end.clear();
        G.push_back({});
        is_end.push_back(false); 

        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            int cur = 0;
            for (char c : s) {
                int target = c - 'a';
                
                if (G[cur].find(target) == G[cur].end()) {
                    G[cur][target] = G.size(); 
                    G.push_back({});
                    is_end.push_back(false); 
                }
                cur = G[cur][target];
            }
            is_end[cur] = true;
        }
        
        dfs(0, 1);
        
        cout << ans/(double)n << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed;
    cout.precision(2);

    solve();

    return 0;
}