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
vector<bool> global_vis;

pii bfs(int start, int n) {
    queue<int> q;
    vector<int> dist(n + 1, -1);
    
    q.push(start);
    dist[start] = 1;
    
    int max_dist = 1;
    int max_idx = start;
    
    while(!q.empty()) {
        int cur = q.front(); 
        q.pop();
        
        if (degree[cur] >= 4) global_vis[cur] = true;
        
        for (int next : adj[cur]) {
            if (dist[next] != -1) continue; 
            
            if (degree[next] >= 4) {
                dist[next] = dist[cur] + 1;
                q.push(next);
                if (dist[next] > max_dist) {
                    max_dist = dist[next];
                    max_idx = next;
                }
            } 
            else if (degree[next] == 3) {
                dist[next] = dist[cur] + 1;
                if (dist[next] > max_dist) {
                    max_dist = dist[next];
                    max_idx = next;
                }
            }
        }
    }
    return {max_dist, max_idx};
}

void solve() {
    int n; 
    cin >> n;
    
    degree.assign(n + 1, 0);
    adj.assign(n + 1, vector<int>());
    global_vis.assign(n + 1, false);
    int ans = 1;
    
    for (int i = 0; i < n - 1; ++i) { 
        int u, v; 
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (degree[i] >= 4 && !global_vis[i]) {
            auto [dist1, nodeA] = bfs(i, n);
            auto [dist2, nodeB] = bfs(nodeA, n);
            ans = max(ans, dist2);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 3) {
            for (int next : adj[i]) {
                if (degree[next] >= 3) ans = max(ans, 2);
            }
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}
