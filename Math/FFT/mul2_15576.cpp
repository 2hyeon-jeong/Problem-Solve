// Problem: BOJ 15576

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

typedef complex<double> cpx;
const double PI = acos(-1);

void fft(vector<cpx> &v, cpx w) {
    int n = sz(v);
    if (n == 1) return;

    vector<cpx> even(n/2), odd(n/2);
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) even[i/2] = v[i];
        else odd[i/2] = v[i];
    }

    fft(even, w*w);
    fft(odd, w*w);
    cpx z(1, 0);
    for (int i = 0; i < n/2; ++i) {
        v[i] = even[i] + z * odd[i];
        v[i + n/2] = even[i] - z * odd[i];

        z *= w;
    }    
}

vector<int> multiply(vector<int> a, vector<int> b) {
    int n = 1;
    while(n <= sz(a) || n <= sz(b)) n *= 2;
    n *= 2;
    
    a.resize(n); b.resize(n);
    vector<int> c(n);
    vector<cpx> fa(n), fb(n);
    for (int i = 0; i < n; ++i) {
        fa[i] = cpx(a[i], 0);
        fb[i] = cpx(b[i], 0);
    }
    cpx unit(cos(2*PI/n), sin(2*PI/n));

    fft(fa, unit);
    fft(fb, unit);

    vector<cpx> fc(n);
    for (int i = 0; i < n; ++i) fc[i] = fa[i] * fb[i];

    fft(fc, cpx(1, 0)/unit);
    for(int i = 0; i < n; ++i) fc[i] /= cpx(n, 0);
    for(int i = 0; i < sz(c); ++i) c[i] = round(fc[i].real());

    for(int i = 0; i < n - 1; ++i) {
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }

    return c;
}

void solve() {
    string sa, sb; cin >> sa >> sb;
    vector<int> a(sz(sa)), b(sz(sb));
    for (int i = 0; i < sz(a); ++i) {
        int idx = sz(a) - i - 1;
        a[i] = sa[idx] - '0';
    }
    for (int i = 0; i < sz(b); ++i) {
        int idx = sz(b) - i - 1;
        b[i] = sb[idx] - '0';
    }
    vector<int> c = multiply(a, b);
    int i = sz(c) - 1;
    while(i > 0 && c[i] == 0) i--;

    for (; i >= 0; --i) {
        cout << c[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}