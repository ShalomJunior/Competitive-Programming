#include <bits/stdc++.h>
#define ll long long
#define pr pair<int,ll> 
#define mp make_pair

using namespace std;
const ll INF = 1e17;

vector<vector<pr>> adj;
vector<ll> dis;
vector<bool> vis;

void compute(int r) {
    int n = dis.size() - 1;
    for (int i = 1; i <= n; i++)dis[i] = INF;

    priority_queue<pr> pq;
    dis[r] = 0;
    pq.push(mp(0, r));

    while (!pq.empty()) {
        auto a = pq.top().second; pq.pop();
        if (vis[a])continue;
        vis[a] = true;
        for (auto& p : adj[a]) {
            int b = p.first; ll w = p.second;
            if (dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
                pq.push(mp(-dis[b], b));
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    adj.resize(n + 1); dis.resize(n + 1); vis.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; ll c; cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
    }
    compute(1);

    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
}