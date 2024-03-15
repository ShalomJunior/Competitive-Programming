#include <bits/stdc++.h>

using namespace std;

vector<int> dis;
vector<bool> proc;
vector<vector<pair<int, int>>> adj;

void compute(int r, int d) {
    int n = dis.size() - 1;
    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX;

    priority_queue<pair<int, int>> pq;
    dis[r] = 0;
    pq.push({ 0, r });
    while (!pq.empty()) {
        int a = pq.top().second; pq.pop();
        if (proc[a])continue;
        proc[a] = true;
        for (auto& e : adj[a]) {
            int b = e.first, w = e.second;
            if (dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
                pq.push({ -dis[b], b });
            }
        }
    }
}

int main() {
    int t, n, v;
    cin >> t >> n >> v;

    dis.resize(n + 1);
    proc.resize(n + 1);
    adj.resize(n + 1);

    unordered_map<char, int> h;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        h[c] = i;
    }

    char loc, des; cin >> loc >> des;
    loc = h[loc]; des = h[des];

    for (int i = 0; i < v; i++) {
        char s, e; int w;
        cin >> s >> e >> w;
        s = h[s]; e = h[e];
        adj[s].push_back({ e,w });
        adj[e].push_back({ s,w });
    }

    compute(loc, des);

    if (dis[des] <= t) cout << "possible";
    else cout << "impossible" << endl;
}