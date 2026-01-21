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
    int n; 
    cin >> n;
    
    vector<int> cnt(n + 1, 0);
    
    for (ll i = 1; i * i < n; ++i) {
        for (ll j = i + 1; i * i + j * j <= n; ++j) {
            ll val = i * i + j * j;
            cnt[val]++;
        }
    }
    int ans = 0;
    for (int k = 1; k <= n; ++k) {
        if (cnt[k] == 1) {ans ++;}
    }
    cout << ans << endl;
    for (int k = 1; k <= n; ++k) {
        if (cnt[k] == 1) {cout << k << " ";}
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}