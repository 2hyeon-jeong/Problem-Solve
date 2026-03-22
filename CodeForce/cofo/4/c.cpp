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

// 각각 약수들의 길이로 전부 교집합 확인하기 -> c++은 교집합 하기 어려우니까 비트마스킹으로

void solve() {
    int n, k; cin >> n >> k;
    vector<string> s(k);
    for (int i = 0; i < k; ++i) cin >> s[i];
    vector<int> col(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            col[i] = col[i] | (1 << s[j][i] - 'a');
        }
    }

    for (int step = 1; step <= n; ++step) {
        if (n % step != 0) continue;
        string pattern = "";
        bool possible = true;
        for (int start = 0; start < step; ++start) {
            int temp = (1 << 26) - 1;
            for (int rep = 0; rep < (n / step); ++rep) {
                temp &= col[start + rep * step];
            }
            if (temp == 0) {
                possible = false;
                break;
            }
            pattern += (char)('a' + __builtin_ctz(temp));
        }
        if (possible) {
            for (int i = 0; i < n / step; ++i) {
                cout << pattern;
            }
            cout << endl;
            return;
        }
    }
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}