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

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> times(n+1);
    vector<int> ind(n+1, 0);
    vector<int> dp(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> times[i];
        int t;
        while (1) {
            cin >> t;
            if (t == -1) break;
            adj[t].push_back(i);
            ind[i] += 1;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) {q.push(i); dp[i] = times[i];}
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : adj[cur]) {
            ind[next] -= 1;
            dp[next] = max(dp[next], dp[cur] + times[next]);
            if (ind[next] == 0) {
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << dp[i] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}