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
double ans;
int n;

void dfs(int node) {
    for (auto& edge : G[node]) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (G[node].find(i) == G[node].end() || is_end[node]) {
                cnt ++;
            }
        }
        if (cnt > 1) {
            ans ++;
        }
        dfs(edge.second);
    }
}

void solve() {
    while(cin >> n) {
        G.clear(); G.resize(800001);
        is_end.clear(); is_end.resize(800001);
        ans = 0;
        int node_cnt = 1;
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            string s; cin >> s;
            for (char k : s) {
                int c = k - '0';
                if (G[cur].find(c) == G[cur].end()) {
                    G[cur][c] = node_cnt++;
                }
                cur = G[cur][c];
            }
            is_end[cur] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}