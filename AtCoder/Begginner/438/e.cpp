#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

const int MAXN = 32;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n+1, 0);
    vector<vector<ll>> table;
    vector<vector<ll>> water;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    table.resize(MAXN, vector<ll>(n+1, 0));
    water.resize(MAXN, vector<ll>(n+1, 0));
    for (int i = 1; i <= n; ++i) {table[0][i] = a[i]; water[0][i] = i;}
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j <= n; ++j) {
            table[i][j] = table[i-1][table[i-1][j]];
            int start = table[i-1][j];
            water[i][j] = water[i-1][j] + water[i-1][start];
        }
    }

    while(q--) {
        ll t, b; cin >> t >> b;
        ll ans = 0;
        int node = b;
        for (int i = 0; i < MAXN; ++i) {
            if ((t >> i) & 1) {
                ans += water[i][node];
                node = table[i][node];
            }
        }
        cout << ans << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}