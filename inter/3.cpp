#include <bits/stdc++.h>
using namespace std;

int count(int edgeNode, int k, vector<int>& cost, vector<int>& edgeFrom, vector<int>& egdeTo) {
    vector<vector<int>> adj(edgeNode);
    for (int i = 1; i < edgeNode; i++) {
        adj[edgeFrom[i] - 1].push_back(egdeTo[i] - 1);
        adj[egdeTo[i] - 1].push_back(edgeFrom[i] - 1);
    }

    vector<int> p(edgeNode);
    //p[i] is the parent of the vertex i
    vector<int> vis(edgeNode);
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                p[c] = r;
                dfs(c);
            }
        }
        };
    long long ans = 0;
    for (int i = 0; i < edgeNode; i++) {
        long long cnt = 0;
        int x = i;
        do {
            cnt += cost[x];
            cnt %= k;
            if (cnt == 0) ans++;
            if (x == 0) break;
            x = p[x];

        } while (true);
    }
    return ans;
}


//N < 10^4


//N = 10^5

long long count(int n, vector<int>& cost, vector<int>& from, vector<int>& to, int k) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        adj[from[i] - 1].push_back(to[i] - 1);
        adj[to[i] - 1].push_back(from[i] - 1);
    }
    long long ans = 0;
    map<int, int> h;
    h[0]++;
    vector<bool> vis(n);
    function<void(int, long long)> dfs = [&](int r, long long pre) {
        vis[r] = true;
        pre += cost[r];
        ans += h[pre % k];
        h[pre % k]++;
        for (auto& c : adj[r]) {
            if (!vis[c]) dfs(c, pre);
        }
        h[pre % k]--;
        };
    dfs(0, 0);
    return ans;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> from(n - 1), to(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];
    }
    vector<int> cost(n);
    for (auto& c : cost) cin >> c;
    cout << count(n, cost, from, to, k) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
