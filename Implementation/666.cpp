// Problem: BOJ 1436

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

bool check(int x) {
    vector<int> temp;
    while(x > 0) {
        temp.push_back(x%10);
        x /= 10;
    }
    for (int i = 0; i <= sz(temp) - 3; ++i) {
        int t1 = temp[i];
        int t2 = temp[i+1];
        int t3 = temp[i+2];
        if (t1 == 6 && t2 == 6 && t3 == 6) return true;
    }
    return false;
}

void solve() {
    int m = 10000;
    vector<int> ans;
    for (int i = 666; sz(ans) < m; ++ i) {
        if (check(i)) ans.push_back(i);
    }
    int n; cin >> n;
    cout << ans[n-1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}