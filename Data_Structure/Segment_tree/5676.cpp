// Problem: BOJ 5676

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<ll> tree;
vector<int> a;

int convert(ll x) {
    if (x == 0) return 0;
    else if (x > 0) return 1;
    else return -1;
}

void init(int node, int s, int e) {
    if (s == e) {
        tree[node] = convert(a[s]);
        return;
    }
    int m = (s + e) / 2;
    init(node * 2, s, m);
    init(node * 2 + 1, m + 1, e);
    tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

void update(int node, int s, int e, int idx, ll x) {
    if (idx < s || e < idx) return;
    if (s == e) {
        a[idx] = convert(x);
        tree[node] = a[idx];
        return;
    }
    int m = (s + e) / 2;
    update(2*node, s, m, idx, x);
    update(2*node+1, m+1, e, idx, x);
    tree[node] = tree[2*node] * tree[2*node+1];
}

int query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 1;
    if (l <= s && e <= r) return tree[node];
    int m = (s + e) / 2;
    return query(node * 2, s, m, l, r) * query(node * 2 + 1, m + 1, e, l, r);
}

void solve() {
    int n, k;
    while(cin >> n >> k) {
        tree.resize(4*n+1, 1);
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            ll t; cin >> t;
            a[i] = convert(t);
        }
        init(1, 0, n-1);
        while(k--) {
            char type; cin >> type;
            if(type == 'C') {
                int idx, v; cin >> idx >> v;
                update(1, 0, n-1, idx-1, v);
            }
            else {
                int i, j; cin >> i >> j;
                int res = query(1, 0, n - 1, i - 1, j - 1);
                if (res > 0) cout << "+";
                else if (res < 0) cout << "-";
                else cout << "0";
            }
        }
        cout << endl;
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