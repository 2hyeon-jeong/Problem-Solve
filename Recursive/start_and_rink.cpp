// Problem: BOJ 14889

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

int points[101][101];
int n, ans; 
int used[101] = {0};

int get_point() {
    int a = 0; int b = 0;
    for (int i = 1; i <= n; ++i) {
        if (used[i]) {
            for (int j = 1; j <= n; ++j) {
                if (used[j]) a += points[i][j];
            }
        }
        else {
            for (int j = 1; j <= n; ++j) {
                if (!used[j]) b += points[i][j];
            }
        }
    }
    return abs(a-b);
}

void dfs(int s, int dep) {
    if (n / 2 == dep) {
        ans = min(ans, get_point());
        return;
    }

    for (int i = s; i <= n; ++i) {
        if (used[i]) continue;
        used[i] = 1;
        dfs(i + 1, dep + 1);
        used[i] = 0;
    }

}

void solve() {
    cin >> n;
    ans = (1<<30);
    for(int i = 1; i<=n;++i) {
        for(int j = 1; j<=n;++j) {
            cin >> points[i][j];
        }
    }

    dfs(1, 0);
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