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
    int n, d; cin >> n >> d;
    vector<int> buy(n);
    vector<int> use(n);
    for (int i = 0; i < n; ++i) cin >> buy[i];
    for (int i = 0; i < n; ++i) cin >> use[i];

    queue<pii> q;
    for (int i = 0; i < n; ++i) {
        q.push({buy[i], i});
        while(use[i] != 0) {
            if (q.front().first < use[i]) {
                use[i] -= q.front().first;
                q.pop();
            }
            else if (q.front().first == use[i]) {
                use[i] = 0;
                q.pop();
            }
            else {
                q.front().first -= use[i];
                use[i] = 0;
            }
        }
        while(!q.empty() && i - q.front().second >= d) q.pop();
    }
    int remain = 0;
    while(!q.empty()) {
        remain += q.front().first;
        q.pop();
    }
    cout << remain << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}