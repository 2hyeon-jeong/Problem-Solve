// Problem: BOJ 5052

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct TrieNode {
    bool is_end;
    TrieNode* child[10];
    TrieNode() {
        is_end = false;
        for (int i = 0; i < 10; ++i) child[i] = NULL;
    }
};

struct Trie {
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    bool insert(string s) {
        TrieNode* cur = root;
        for (char c : s) {
            int num = c - '0';
            if (cur->child[num] == NULL) {
                cur->child[num] = new TrieNode();
            }
            cur = cur->child[num];
            if (cur->is_end) return false;
        }
        cur->is_end = true;
        for (int i = 0; i < 10; ++i) {
            if (cur->child[i] != NULL) return false;
        }
        return true;
    }
};

void solve() {
    Trie trie = Trie();
    int n; cin >> n;
    bool ans = true;
    while (n--) {
        string s; cin >> s;
        ans = ans & trie.insert(s);
    }
    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}