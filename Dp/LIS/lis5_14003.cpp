// Problem: BOJ 14003

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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<ll> lis;
    vector<ll> real_lis;
    vector<ll> records(n);
    lis.push_back(a[0]);
    records[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (lis.back() < a[i]) {
            lis.push_back(a[i]);
            records[i] = sz(lis) - 1;
        }
        else {
            int idx = lower_bound(all(lis), a[i]) - lis.begin();
            lis[idx] = a[i];
            records[i] = idx;
        }
        debug(lis);
        debug(records);
    }
    int t = sz(lis) - 1;
    for (int i = n-1; i >= 0; --i) {
        debug(t);
        debug(records[i]);
        if (t == records[i]) {
            real_lis.push_back(a[i]);
            t--;
        }
    }
    cout << sz(real_lis) << endl;
    reverse(all(real_lis));
    for (ll i : real_lis) cout << i << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}