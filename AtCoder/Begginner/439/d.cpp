#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    int n; cin >> n;
    ll ans = 0;
    unordered_map<ll, ll> m;
    unordered_map<ll, ll> m2;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        ll t; cin >> t;
        m[t]++;
        v[i] = t;
    }
    for (int i = 0; i < n; ++i) {
        if (v[i] % 5 == 0) {
            int k = v[i] / 5;
            if (m2.count(3*k) && m2.count(7 * k)) {
                ans += m2[3*k] * m2[7*k];
            }
            ans += (m[3*k] - m2[3*k]) * (m[7*k] - m2[7*k]);
        }
        m2[v[i]] ++;
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