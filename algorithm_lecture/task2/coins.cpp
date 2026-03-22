#include <bits/stdc++.h>

using namespace std;

int total, M, d;
vector<int> coins;
int m = (1<<30);

void dfs(int s, int cnt) {
    if (total > M) return;
    if (total == M) {
        m = min(m, cnt);
    }
    for (int i = s; i < d; ++i) {
        total += coins[i];
        dfs(i, cnt+1);
        total -= coins[i];
    }

}

void solve() {
    cin >> M;
    cin >> d;
    coins.resize(d);
    for (int& i : coins) cin >> i;
    dfs(0, 0);
    if (m == (1<<30)) m = -1;
    cout << m << "\n";
    cout << "알고리즘 2분반 20222110482 정이현" << "\n";
}

int main() {
    solve();
    return 0;
}