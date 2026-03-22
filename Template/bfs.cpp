#include <bits/stdc++.h>
using namespace std;

int bfs_graph(int start, int n, const vector<vector<int>>& adj) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int nxt : adj[curr]) {
            if (dist[nxt] != -1) continue;
            
            dist[nxt] = dist[curr] + 1;
            q.push(nxt);
        }
    }
    
    return -1;
}