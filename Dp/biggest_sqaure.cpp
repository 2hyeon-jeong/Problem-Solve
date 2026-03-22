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
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    // dp[i][j] -> i, j가 오른쪽 하단의 위치일 때 
    // i, j를 포함하는 정사각형 중 가장 큰 정사각형의 변의 길이
    vector<vector<int>> dp(n, vector<int>(m, (0)));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string t; cin >> t;
        for (int j = 0; j < m; ++j) {
            char c = t[j];
            if (c == '0') arr[i][j] = 0;
            else arr[i][j] = 1;
            if (i == 0 || j == 0) dp[i][j] = arr[i][j];
            ans = max(ans, arr[i][j]);
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            // i, j가 0이면 i, j를 포함하는 정사각형은 없기에 0
            if (arr[i][j] == 0) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans * ans  << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}