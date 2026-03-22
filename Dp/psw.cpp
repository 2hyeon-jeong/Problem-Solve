// Problem: BOJ 1086

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

ll fact(int x) {
    ll ret = 1;
    for (int i = 2; i <= x; ++i) ret *= i;
    return ret;
}

int get_mod(const string& s, int k) {
    int ret = 0;
    for (char c : s) {
        ret = (ret * 10 + (c - '0')) % k;
    }
    return ret;
}


void solve() {
    int n; cin >> n;
    vector<int> lens(n), rem(n);
    vector<string> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    int k; cin >> k;
    // 각 원소들의 길이와 나머지 미리 계산
    for (int i = 0; i < n; ++i) {
        lens[i] = sz(nums[i]);
        rem[i] = get_mod(nums[i], k);
    }
    // dp[mask][j] -> mask = 0110 -> 2, 3번째를 사용해서 나머지가 j인 개수 
    vector<vector<ll>> dp((1<<n), vector<ll>(k, 0));
    dp[0][0] = 1;

    // 최대 길이가 50이니 먼저 계산해놓기
    vector<int> ten(51, 1);
    for (int i = 1; i <= 50; ++i) {
        ten[i] = (ten[i - 1] * 10) % k;
    }


    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int mod = 0; mod < k; ++ mod) {
            // mask만큼 사용해서 mod가 나온 경우가 없다면 넘기기
            if (dp[mask][mod] == 0) continue;
            for (int i = 0; i < n; ++i) {
                // 마스크 재사용 방지
                if (mask & (1 << i)) continue;

                int next_mask = mask | (1 << i);
                int next_mod = (mod * ten[lens[i]] + rem[i]) % k;

                dp[next_mask][next_mod] += dp[mask][mod];
            }
        }
    }

    ll p = dp[(1<<n) -1][0];
    ll q = fact(n);
    ll g = gcd(p, q);
    cout << p / g << "/" << q / g << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}