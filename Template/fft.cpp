// Problem: BOJ 

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
vector<double> a;


void FFT(vector<cpx>& v, cpx w) {
    int n = sz(v);
    if (n == 1) return;
    
    vector<cpx> even(n/2), odd(n/2);
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) even[i/2] = v[i];
        else odd[i/2] = v[i];
    }

    FFT(even, w*w);
    FFT(odd, w*w);

    cpx z(1, 0);
    for(int i=0; i<n/2; i++) {
        v[i] = even[i] + z*odd[i];
        v[i + n/2] = even[i] - z*odd[i];

        z *= w;
    }
}


void solve() {
    vector<cpx> v = {0, 1, 2, 3};
    int n = 4;
    cpx unit(cos(2*PI/n), sin(2*PI/n));
    FFT(v, unit);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}