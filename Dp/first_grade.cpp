// Problem: BOJ 5557

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
    vector<int> nums(n+1, 0);
    for (int i = 1; i <= n; ++i) cin >> nums[i];
    vector<vector<ll>> dp(n+1, vector<ll>(21, 0));
    dp[1][nums[1]] = 1;
    for (int i = 2; i < n; ++i) {
        for (int j = 0; j < 21; ++j) {
            int k = j + nums[i];
            if (0 <= k && k <= 20) {
                dp[i][k] += dp[i-1][j];
            }
            k = j - nums[i];
            if (0 <= k && k <= 20) {
                dp[i][k] += dp[i-1][j];
            }
        }
    }

    cout << dp[n-1][nums[n]] << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}