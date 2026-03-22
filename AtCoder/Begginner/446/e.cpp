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
    int m, a, b; cin >> m >> a >> b;
    vector<vector<int>> adj(m * m + 1);
    vector<int> node(m * m + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            int cur = m * i + j;
            node[cur] = (a * j + b * i) % m;
            int next = m * j + node[cur];
            adj[next].push_back(cur);
        }
    }
    int cnt = 0;
    queue<int> q;
    vector<bool> v(m * m + 1, false);
    for (int i = 0; i < m; ++i) {
        q.push(i * m);
        cnt += 1;
        v[i * m] = true;
    }
    for (int j = 1; j < m; ++j){
        q.push(j);
        v[j] = true;
        cnt += 1;
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : adj[cur]) {
            if (!v[next]) {
                v[next] = true;
                q.push(next);
                cnt += 1;
            }
        }
    }

    cout << m * m - cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}