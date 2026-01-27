// Problem: BOJ 14572

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
    int N, K, D; cin >> N >> K >> D;
    vector<vector<int>> people(N);
    vector<int> cnt(K+1, 0);
    vector<vector<int>> can(N);
    for (int i = 0; i < N; ++i) {
        int M, d; cin >> M >> d;
        people[i] = {d, M, i};
        for (int j = 0; j < M; ++j) {
            int a; cin >> a;
            can[i].push_back(a);
        }
    }
    sort(all(people));
    int L = 0; int R = 0;
    ll ans = 0;
    while(L != N - 1) {
        if (L > R) R = L;
        while(R < N && people[R][0] - people[L][0] <= D) {
            for (int c : can[people[R][2]]) {
                cnt[c]++;
            }
            R++;
        }
        int current_size = R - L;
        
        if (current_size > 0) {
            int uni = 0;
            int inter = 0;
            for (int i = 1; i <= K; ++i) {
                if (cnt[i] >= 1) uni++;
                if (cnt[i] == current_size) inter++;
            }
            ans = max(ans, (ll)(uni - inter) * current_size);
        }
        debug(ans);
        for (int c : can[people[L][2]]) {
                cnt[c]--;
        }
        L++;
    }
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