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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    ll s = 0;
    ll k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            s += grid[i][j];
        }
    }
    k = s / 2;
    if (s == 0 || s == 1) {
        cout << 0 << endl;
        cout << string(n, 'D') << string(m, 'R') << endl;
        return;
    }
    cout << (k * (s - k)) << endl;
    ll cur_ones = 0;
    int target_r = -1, target_c = -1;
    bool found = false;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            cur_ones += grid[i][j];
            if (cur_ones == k) {
                target_r = i;
                target_c = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }
    /*
        r, c에서 딱 절반이 나눠지는 상황 -> r, c까지 1을 절대 포함할 수 없게 벽타고 내려오고 c까지 바로 직진
        그 이후 한칸 내려오고 다시 직전 후 벽타면서 내려가기
    */
    string path = "";
    for (int i = 0; i < target_r; ++i) path += 'D';
    for (int i = 0; i <= target_c; ++i) path += 'R';
    path += 'D';
    for (int i = 0; i < m - (target_c + 1); ++i) path += 'R';
    for (int i = 0; i < n - (target_r + 1); ++i) path += 'D';

    cout << path << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}