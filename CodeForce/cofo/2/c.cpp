#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*

*/

void solve() {
    ll n, l, r, k; cin >> n >> l >> r >> k;
    if (n % 2 == 1) cout << l << endl;
    else {
        if (n == 2) {
            cout << - 1 << endl;
            return;
        }
        ll i = 64 - __builtin_clzll(l);
        ll t = (1LL << i);
        if (t > r) {
            cout << -1 << endl;
            return;
        }
        if (k <= (n-2)) cout << l << endl;
        else cout << t << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}