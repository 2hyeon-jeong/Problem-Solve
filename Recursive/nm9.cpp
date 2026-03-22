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

int n, m;
vector<int> path;
vector<int> nums;
set<vector<int>> s;
bool used[10];

void dfs( int dep) {
    if (dep == m) {
        if (s.find(path) != s.end()) return;
        for (int p:path) cout << p << " ";
        cout << endl;
        s.insert(path);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        used[i] = true;
        path.push_back(nums[i]);
        dfs(dep+1);
        path.pop_back();
        used[i] = false;
    }
}

void solve() {
    cin >> n >> m;
    nums.resize(n);
    for (int i = 0; i < n ;++i) cin >> nums[i];
    sort(all(nums));
    dfs(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}