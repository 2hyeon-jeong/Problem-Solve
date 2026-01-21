#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


// a ^ 1 = LSB 바꾸기 -> 홀수면 -1, 짝수면 + 1


void solve() {
    int a, b, x, y; cin >> a >> b >> x >> y;
    ll ans = 0;
    if (a == b) {cout << 0 << endl; return;}
    else if (a > b) {
        if (a % 2 == 1 && a == b + 1) {cout << y << endl; return;}
        else {cout << -1 << endl; return;}
    }
    while(a != b) {
        if (a % 2 == 0) {
            ans += min(x, y);
        }
        else {
            ans += x;
        }
        a += 1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}