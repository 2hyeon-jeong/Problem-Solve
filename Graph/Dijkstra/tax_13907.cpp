// Problem: BOJ 13907

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

vector<vector<ll>> dist;
vector<vector<pii>> adj;
int n;

void dijkstra(int start) {
    dist[start][0] = 0;
    priority_queue<tuple<int, int, int> , vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, start, 0});
    while(!pq.empty()) {
        auto [cur_cost, cur, cur_cnt] = pq.top(); pq.pop();

        if (dist[cur][cur_cnt] < cur_cost) continue;
        if (cur_cnt >= n - 1) continue;

        for (auto& [next, cost] : adj[cur]) {
            ll total = cur_cost + cost;
            if (total < dist[next][cur_cnt + 1]) {
                dist[next][cur_cnt + 1] = total;
                pq.push({total, next, cur_cnt + 1});
            }
        }
    }
}

void solve() {
    int m, k; cin >> n >> m >> k;
    int s, d; cin >> s >> d;
    adj.resize(n+1);
    dist.resize(n+1, vector<ll>(n+1, (1<<30)));
    while(m--) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    dijkstra(s);
    ll ans = LONG_LONG_MAX;
    for (int i = 1; i < n; ++i) {
        ans = min(ans, dist[d][i]);
    }
    cout << ans << endl;

    ll prefix_p = 0;
    while(k--) {
        int p; 
        cin >> p;
        prefix_p += p;
        
        ans = LONG_LONG_MAX;
        for (int i = 1; i < n; ++i) { 
            ans = min(ans, dist[d][i] + (prefix_p * i));
        }
        cout << ans << endl;
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