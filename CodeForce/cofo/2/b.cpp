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
    int px, py, qx, qy; cin >> px >> py >> qx >> qy;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll max_dist = 0;
    for (int i = 0; i < n; ++i) max_dist += a[i];
    ll min_dist = 0;
    int m = *max_element(all(a));
    min_dist = m - (max_dist - m);
    if (min_dist < 0) min_dist = 0;
    ll dx = px - qx;
    ll dy = py - qy;
    double dist = sqrt(dx * dx + dy * dy);
    if (min_dist <= dist && dist <= max_dist) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
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