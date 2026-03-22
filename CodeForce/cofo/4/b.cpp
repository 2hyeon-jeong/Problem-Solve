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

/*
    A -> C
    B -> C
    ----
    A -> B -> C, B가 남는 걸 전부 다 쓸 수 있다면 더 커지는 상황이 있을 수도 있음
    B의 자투리 = r
    A -> B로 보내는 돈 kx -> ky
    B의 돈: r + ky
    r + ky >= kx + x를 만족해야함
    r >= k(x - y) + x 는 모순 r < x이여야함
*/

void solve() {
    ll n, x, y; cin >> n >> x >> y;
    ll ans = 0;
    vector<ll> banks(n);
    vector<ll> can_send(n, 0);
    for (int i = 0; i < n; ++i) cin >> banks[i];
    for (int i = 0; i < n; ++i) {
        can_send[i] = (banks[i] / x) * y;
    }
    ll total = 0;
    for (ll i : can_send) total += i;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, banks[i] + total - can_send[i]);
    }
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