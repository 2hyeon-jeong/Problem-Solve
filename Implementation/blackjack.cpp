#include<bits/stdc++.h>

using namespace std;

void solve() {
    // 세 게의 카드를 골라서 m을 넘지 않은 것들 중에서 m이랑 가장 가까운 수를 찾기
    int n, m; cin >> n >> m;
    vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int t = cards[i] + cards[j] + cards[k];
                if (t <= m) {
                    ans = max(ans, t);
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}