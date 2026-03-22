// Problem: BOJ 1126

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

    int n;cin>>n;
    vector<vector<int>> dp(n+1,vector<int>(1+5e5,-1));
    dp[0][0] = 0;
    vector<int> v(n);
    for(int& x : v) cin >> x;
    for(int i=1,x;i<=n;i++) {
        x=v[i-1];
        for(int j = 0; j <= 5e5; j++) {
            if(!~dp[i-1][j])continue;
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            dp[i][j+x]=max(dp[i][j+x],dp[i-1][j]+x);
            if(x>j)
                dp[i][x-j]=max(dp[i][x-j],dp[i-1][j]+x-j);
            else
                dp[i][j-x]=max(dp[i][j-x],dp[i-1][j]);
        }
    }
    cout<<(dp[n][0] <= 0 ? -1 : dp[n][0]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}