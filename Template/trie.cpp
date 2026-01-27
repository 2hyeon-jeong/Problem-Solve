#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SIZE = 10;

struct TrieNode {

    TrieNode* child[SIZE];
    bool is_end;

    TrieNode() {
        fill(child, child + SIZE, NULL);
        is_end = false;
    }

    ~TrieNode() {
        for (int i = 0; i < SIZE; ++i) {
            if (child[i]) delete child[i];
        }
    }

};

struct Trie {

    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode* cur = root;
        for (char c : s) {
            if (cur->child[c - '0'] == NULL) {
                cur->child[c - '0'] = new TrieNode();
            }
            cur = cur->child[c - '0'];
        }
        cur->is_end = true;
    }

    bool search(string s) {
        TrieNode* cur = root;
        for (char c : s) {
            if (cur->child[c - '0'] == NULL) return false;
            cur = cur->child[c - '0'];
        }
        return cur->is_end;
    }
};

vector<map<int, int>> trie;
vector<bool> is_end;
int node_id;

void insert(string s) {
    int cur = 0;
    for (char c : s) {
        if(trie[cur].find(c - '0') == trie[cur].end()) {
            trie[cur][c - '0'] = node_id++;
        }
        cur = trie[cur][c - '0'];
    }
    is_end[cur] = true;
}

bool search(string s) {
    int cur = 0;
    for (char c : s) {
        if (trie[cur].find(c - '0') == trie[cur].end()) return false;
        cur = trie[cur][c - '0'];
    }
    return is_end[cur];
}

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}