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

bool cmp(const pll& a, const pll& b) {
    if (a.first == b.first) return b.second < a.second;
    return a.first < b.first;
}

void solve() {
    int n; cin >> n;
    vector<pll> v;
    vector<ll> lis;
    for(int i = 0; i < n; ++i) {
        ll a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(all(v), cmp);
    debug(v);
    lis.push_back(v[0].second);
    for (int i = 1; i < n; ++i) {
        debug(lis);
        auto [f, s] = v[i];
        if (lis.back() < s) {
            lis.push_back(s);
        }
        else {
            auto it = lower_bound(all(lis), s);
            *it = s;
        }
    }
    cout << sz(lis) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}