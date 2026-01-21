#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int calc(int n) {
    int ans = 0;
    while(n > 0) {
        ans +=(n%10) * (n%10);
        n /= 10;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    unordered_set<int> s;
    while(s.find(n) == s.end()) {
        if (n == 1) {
            cout << "Yes" << endl;
            return;
        }
        s.insert(n);
        n = calc(n);
    }
    cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}