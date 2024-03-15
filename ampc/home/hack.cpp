#include<bits/stdc++.h>

using namespace std;

vector<bool> vis;
vector<int> dist;
vector<vector<pair<int, int>>> adj;

void compute(int root) {
    for (int i = 0; i < vis.size(); ++i)
        dist[i] = INT_MAX;
    priority_queue<pair<int, int>> pq;

    pq.push({ root,0 });
    dist[root] = 0;
    while (!pq.empty()) {
        int a = pq.top().first; pq.pop();
        if (vis[a]) continue;
        vis[a] = true;
        for (auto pr : adj[a]) {
            int b = pr.first, w = pr.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                pq.push({ b, -dist[b] });
            }
        }
    }
}

int main() {
    int t; cin >> t;
    int n, v; cin >> n >> v;
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        mp[c] = mp.size() + 1;
    }

    char start, dest; cin >> start >> dest;
    start = mp[start]; dest = mp[dest];
    vis.resize(n + 1);
    adj.resize(n + 1);
    dist.resize(n + 1);
    for (int i = 0; i < v; i++) {
        char a, b; int w; cin >> a >> b >> w;
        a = mp[a]; b = mp[b];
        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
    }

    compute(start);
    cout << ((dist[dest] <= t) ? "possible" : "impossible") << endl;
}