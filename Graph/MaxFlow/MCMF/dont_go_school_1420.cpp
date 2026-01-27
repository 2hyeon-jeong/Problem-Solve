// Problem: BOJ 1420

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

struct Edge {
    int to, capacity, flow, rev;
};
const int MAXN = 10000;
int n, m;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
vector<vector<Edge>> adj;
vector<int> parent_node;
vector<int> parent_idx;
void add_edge(int from, int to, int cap) {
    adj[from].push_back({to, cap, 0, sz(adj[to])});
    adj[to].push_back({from, 0, 0, sz(adj[from]) - 1});
}

int get_in(int r, int c) { return r*m + c; }
int get_out(int r, int c) { return r*m + c + MAXN; }

int max_flow(int source, int sink) {
    int tot = 0;
    while(1) {
        fill(all(parent_node), -1);
        fill(all(parent_idx), -1);
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for (int i = 0; i < sz(adj[cur]); ++i) {
                Edge& e = adj[cur][i];
                if (e.capacity - e.flow > 0 && parent_node[e.to] == -1) {
                    q.push(e.to);
                    parent_node[e.to] = cur;
                    parent_idx[e.to] = i;
                }
            }
        }
        if (parent_node[sink] == -1) break;
        int flow = (1<<30);
        for (int v = sink; v != source; v = parent_node[v]) {
            int u = parent_node[v];
            int idx = parent_idx[v];
            flow = min(flow, adj[u][idx].capacity - adj[u][idx].flow);
        }

        for (int v = sink; v != source; v = parent_node[v]) {
            int u = parent_node[v];
            int idx = parent_idx[v];
            int rev_idx = adj[u][idx].rev;
            adj[u][idx].flow += flow;
            adj[v][rev_idx].flow -= flow;
        }
        tot += flow;
    }
    return tot;
}


void solve() {
    cin >> n >> m;
    adj.resize(2 * MAXN + 5);
    parent_node.resize(2 * MAXN + 5);
    parent_idx.resize(2*MAXN + 5);
    pii source, sink;
    vector<string> graph(n);
    for (int i = 0; i < n; ++i) cin >> graph[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c = graph[i][j];
            if (c == '#') continue;
            if (c == '.') add_edge(get_in(i, j), get_out(i, j), 1);
            else if (c == 'K') {add_edge(get_in(i, j), get_out(i, j), (1<<30)); source = {i, j};}
            else if (c == 'H') {add_edge(get_in(i, j), get_out(i, j), (1<<30)); sink = {i, j};}
            for (int k = 0; k < 4; ++k) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (graph[nr][nc] != '#') {
                    add_edge(get_out(i, j), get_in(nr, nc), (1 << 30));
                }
            }
        }
    }
    if (abs(source.first - sink.first) + abs(source.second - sink.second) == 1) {
        cout << -1 << endl;
        return;
    }

    cout << max_flow(get_in(source.first, source.second), get_out(sink.first, sink.second)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}