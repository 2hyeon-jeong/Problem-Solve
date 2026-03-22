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
    string s, t; cin >> s >> t;
    string not_a_s, not_a_t;
    vector<int> a_cnt_s, a_cnt_t;
    
    int cnt = 0;
    for (char c : s) {
        if (c == 'A') cnt++;
        else {
            not_a_s.push_back(c);
            a_cnt_s.push_back(cnt);
            cnt = 0;
        }
    }
    a_cnt_s.push_back(cnt);

    cnt = 0;
    for (char c : t) {
        if (c == 'A') cnt++;
        else {
            not_a_t.push_back(c);
            a_cnt_t.push_back(cnt);
            cnt = 0;
        }
    }
    a_cnt_t.push_back(cnt);

    if (not_a_s != not_a_t) {
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    for (int i = 0; i < sz(a_cnt_s); ++i) {
        ans += abs(a_cnt_s[i] - a_cnt_t[i]);
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
