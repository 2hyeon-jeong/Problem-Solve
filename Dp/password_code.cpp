// Problem: BOJ 2011

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

const int MOD = 1000000;

void solve() {
    string s; cin >> s;
    int n = sz(s);
    vector<int> nums (1, 0);
    for (char c : s) nums.push_back(c - '0');
    debug(nums);
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    if (nums[1] == 0) {
        cout << 0 << endl;
        return;
    }
    for (int i = 2; i <= n; ++i) {
        if (nums[i] == 0 && (nums[i-1] >= 3 || nums[i-1] == 0)) {
            cout << 0 << endl;
            return;
        }
        if (nums[i] == 0) dp[i] = dp[i-2];
        else if (nums[i-1] == 1) dp[i] = dp[i-1] + dp[i-2];
        else if (nums[i-1] == 2 && nums[i] <= 6) dp[i] = dp[i-1] + dp[i-2];
        else dp[i] = dp[i-1];
        dp[i] %= MOD;
    }
    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}