// Problem: BOJ 3640

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
    int to, capacity, flow, cost, rev;
};

vector<vector<Edge>> adj;
vector<int> parent_node;
vector<int> parent_idx;
vector<int> dist;
vector<bool> in_queue;

void add_edge(int from, int to, int cap, int cost) {
    adj[from].push_back({to, cap, 0, cost, sz(adj[to])});
    adj[to].push_back({from, 0, 0, -cost, sz(adj[from]) - 1});
}

int mcmf(int source, int sink) {
    int total_flow = 0; int total_cost = 0;
    while(1) {
        fill(all(parent_node), -1); fill(all(parent_idx), -1);
        fill(all(dist), INT_MAX); fill(all(in_queue), false);
        queue<int> q;
        q.push(source);
        in_queue[source] = true;
        dist[source] = 0;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            in_queue[cur] = false;
            for (int i = 0; i < sz(adj[cur]); ++i) {
                Edge& e = adj[cur][i];
                if (e.capacity - e.flow > 0 && dist[e.to] > dist[cur] + e.cost) {
                    dist[e.to] = dist[cur] + e.cost;
                    parent_node[e.to] = cur;
                    parent_idx[e.to] = i;
                    if (!in_queue[e.to]) {
                        q.push(e.to); in_queue[e.to] = true;
                    }
                }
            }
        }
        if (parent_node[sink] == -1) break;
        int flow = INT_MAX;
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
            total_cost += flow * adj[u][idx].cost;
        }
        total_flow += flow;
    }
    return total_cost;
}

void solve() {
    int v, e;
    while(cin >> v >> e) {
        int source = 1; int sink = v;
        adj.clear(); adj.resize(3 * sink + 1);
        parent_node.resize(3 * sink + 1);
        parent_idx.resize(3 * sink + 1);
        dist.resize(3*sink + 1);
        in_queue.resize(3*sink + 1);
        // 정점 분할
        add_edge(source, source + sink, 2, 0);
        add_edge(sink, sink + sink, 2, 0);
        for (int i = 2; i < sink; ++i) add_edge(i, i + sink, 1, 0);
        while(e--) {
            int a, b, c; cin >> a >> b >> c;
            add_edge(a + sink, b, 1, c);
        }
        cout << mcmf(source, sink + sink) << endl;
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