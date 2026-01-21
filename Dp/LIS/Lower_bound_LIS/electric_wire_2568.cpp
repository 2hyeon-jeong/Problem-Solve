// Problem: BOJ 2568

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
    int ans = 0;
    vector<pll> wires(n);
    vector<ll> lis;
    vector<ll> records(n);
    for (int i = 0; i < n; ++i) {
        ll a, b; cin >> a >> b;
        wires[i] = {a, b};
    }
    sort(all(wires));
    lis.push_back(wires[0].second);
    records[0] = 0;
    for (int i = 1; i < n; ++i) {
        auto [f, s] = wires[i];
        if (lis.back() < s) {
            lis.push_back(s);
            records[i] = sz(lis) - 1;
        }
        else {
            int idx = lower_bound(all(lis), s) - lis.begin();
            lis[idx] = s;
            records[i] = idx;
        }
    }
    debug(lis);
    debug(records);
    vector<bool> is_lis(n, false); 
    int t = sz(lis) - 1;

    for (int i = n - 1; i >= 0; --i) {
        if (records[i] == t) {
            is_lis[i] = true;
            t--;
        }
    }
    cout << n - sz(lis) << endl;

    for (int i = 0; i < n; ++i) {
        if (!is_lis[i]) {
            cout << wires[i].first << endl;
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