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

vector<vector<int>> adj;
vector<int> degree;
vector<pii> edge;
int ans;

int dfs(int cur, int par) {
    int m1 = 0, m2 = 0; 
    
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        
        int val = dfs(nxt, cur);
        if (val > m1) {
            m2 = m1;
            m1 = val;
        } else if (val > m2) {
            m2 = val;
        }
    }
    
    if (degree[cur] >= 4) {
        ans = max(ans, 1 + m1 + m2);
        return 1 + m1;              
    } else if (degree[cur] == 3) {
        ans = max(ans, 1 + m1); 
        return 1;                   
    } else {
        return 0;                    
    }
}

void solve() {
    int n; 
    cin >> n;
    
    degree.assign(n + 1, 0);
    adj.assign(n + 1, vector<int>());
    edge.clear();
    ans = 1;
    
    for (int i = 0; i < n - 1; ++i) { 
        int u, v; 
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
        edge.push_back({u, v});
    }
    
    for (auto& [u, v] : edge) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}
