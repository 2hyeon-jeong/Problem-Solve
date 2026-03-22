// Problem: BOJ 1759

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

int l, c;
vector<int> words;
string str;
int a, b;

void dfs(int s, int dep) {
    if (dep == l) {
        if (a >= 1 && b >= 2) {
            cout << str << endl;
        }
        return;
    }
    for (int i = s; i < c; ++i) {
        char cc = char(words[i]);
        if (cc == 'a' || cc == 'e' || cc == 'i' || cc == 'o' || cc == 'u') {
            a += 1;
            str.push_back(cc);
            dfs(i+1, dep+1);
            str.pop_back();
            a -= 1;
        }
        else {
            b += 1;
            str.push_back(cc);
            dfs(i+1, dep+1);
            str.pop_back();
            b -= 1;
        }
    }
}

void solve() {
    cin >> l >> c;
    words.resize(c);
    // a = 0; b = 0;
    for (int i = 0; i < c; ++i) {
        char t; cin >> t;
        words[i] = t;
    }
    sort(all(words));
    debug(words);
    dfs(0, 0);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}