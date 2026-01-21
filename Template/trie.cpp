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
    TrieNode* child[10];
    bool is_end;
    TrieNode() {
        is_end = false;
        for(int i=0; i<10; i++) child[i] = NULL;
    }

    ~TrieNode() {
        for(int i=0; i<10; i++) {
            if(child[i]) delete child[i];
        }
    }


};

struct Trie {

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string key) {
        TrieNode* cur = root;
        for (char c : key) {
            if (cur->child[c - '0'] == NULL) {
                cur->child[c - '0'] = new TrieNode();
            }
            cur = cur->child[c - '0'];
        }
        cur->is_end = true;
    }

    bool search(string key) {
        TrieNode* cur = root;
        for (char c : key) {
            int idx = c - '0';
            if (cur->child[idx] == NULL) return false;
            cur = cur -> child[idx];
        }
        return cur->is_end;
    }
};


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