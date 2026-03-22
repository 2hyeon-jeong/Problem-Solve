// Problem: BOJ 1067

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

typedef complex<double> cpx;
const double PI = acos(-1);

void fft(vector<cpx> &a, bool invert) {
    // n은 2의 거듭제곱
    int n = sz(a);
    
    vector<int> rev(n);
    for (int i = 0; i < n; i++) {
        rev[i] = (rev[i >> 1] >> 1);
        if (i & 1) rev[i] |= (n >> 1);
    }

    for (int i = 0; i < n; i++)  if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cpx unit_w(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cpx w(1, 0);
            for (int j = 0; j < len / 2; j++) {
                cpx u = a[i + j];
                cpx v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= unit_w;
            }
        }
    }

    if (invert) for (int i = 0; i < n; i++) a[i] /= n;

}

void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n ; ++i) cin >> x[i];
    for (int i = 0; i < n ; ++i) cin >> y[i];
    // x반전 및 y 크기 2배 증가
    reverse(x.begin(), x.end());
    for (int i = 0; i < n; ++i) y.push_back(y[i]);

    int bits = (int)ceil(log2(3*n));
    int size = (1 << bits);

    vector<cpx> fa(size), fb(size);
    for (int i = 0; i < x.size(); ++i) fa[i] = cpx(x[i], 0);
    for (int i = 0; i < y.size(); ++i) fb[i] = cpx(y[i], 0);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < size; ++i) fa[i] *= fb[i];
    fft(fa, true);

    ll ans = 0;
    for (int i = n - 1; i < 2 * n - 1; ++i) {
        ans = max(ans, (ll)round(fa[i].real()));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}