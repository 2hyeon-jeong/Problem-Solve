// Problem: BOJ 

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

const ll MX = 1000000000;
const int MAX_BIT = 29; 

struct Node {
    int child[2];
    int cnt;

    Node() {
        child[0] = child[1] = -1;
        cnt = 0;
    }
};

vector<Node> trie;

int createNode() {
    trie.push_back(Node());
    return sz(trie) - 1;
}

void insert(ll x) {
    int cur = 0;
    trie[cur].cnt++;

    for (int i = MAX_BIT; i >= 0; --i) {
        int bit = ((x >> i) & 1);
        if (trie[cur].child[bit] == -1) {
            trie[cur].child[bit] = createNode();
        }
        cur = trie[cur].child[bit];
        trie[cur].cnt ++;
    }
}

void remove(ll x) {
    int cur = 0;
    trie[cur].cnt--;
    for (int i = MAX_BIT; i >= 0; --i) {
        int bit = (x >> i) & 1;
        cur = trie[cur].child[bit];
        trie[cur].cnt--;
    }
}

ll query(ll x) {
    int cur = 0;
    int result = 0;
    for (int i = MAX_BIT; i >= 0; --i) {
        int bit = (x >> i) & 1;
        // 반대 비트의 자식이 존재 && 반대 비트의 자식의 개수가 0 초과
        if (trie[cur].child[1 - bit] != -1 && trie[trie[cur].child[1-bit]].cnt > 0) {
            result += (1 << i);
            cur = trie[cur].child[1-bit];
        }
        else {
            cur = trie[cur].child[bit];
        }
    }
    return result;
}

void solve() {
    int m; 
    cin >> m;

    trie.reserve(6000005);
    
    createNode(); 
    
    insert(0);

    while(m--) {
        int t, x; 
        cin >> t >> x;
        if (t == 1) insert(x);
        else if (t == 2) remove(x);
        else cout << query(x) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}