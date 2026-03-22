#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<int>> adj(n + 1);
    vector<int> min_in(n + 1, INF);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        min_in[v] = min(min_in[v], u);
    }

    vector<int> D(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    D[1] = 1;
    pq.push({1, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > D[u]) continue;

        for (int v : adj[u]) {
            int nxt_d = max(d, v);
            if (nxt_d < D[v]) {
                D[v] = nxt_d;
                pq.push({nxt_d, v});
            }
        }
    }

    vector<int> diff(n + 2, 0);
    for (int v = 1; v <= n; ++v) {
        if (min_in[v] < v) {
            // k가 min_in[v] 이상, v - 1 이하일 때 v는 경계 밖이므로 지워야 함
            diff[min_in[v]]++;
            diff[v]--;
        }
    }

    int current_deletes = 0;
    int max_d = 0;

    for (int k = 1; k <= n; ++k) {
        // 1부터 k까지 도달하기 위해 거친 정점들의 최댓값 갱신
        max_d = max(max_d, D[k]);
        
        // 현재 k에서 지워야 하는 정점의 개수 누적
        current_deletes += diff[k];

        // 1~k까지 안전하게 도달 가능한 경우
        if (max_d <= k) {
            cout << current_deletes << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}