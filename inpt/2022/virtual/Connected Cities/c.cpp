#include <vector>
#include <set>
#include <iostream>

using namespace std;
vector<vector<int>> adj;
vector<int> blocked;
set<int> visited;
int dfs(int idx) {
    visited.insert(idx);
    if (blocked[idx])
        return 1;
    int c = 1;
    for (auto& v : adj[idx])
        if (!visited.count(v)) {
            visited.insert(v);
            c += dfs(v);
        }
    return c;
}

int main() {
    int m, n;
    cin >> n >> m;
    adj.resize(n + 1);
    blocked.resize(n + 1);
    int a, b;
    for (int idx = 1; idx <= m; ++idx) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int idx = 1; idx <= n; ++idx) {
        int a;
        cin >> a;
        blocked[idx] = a;
    }
    int mx = 1;
    for (int idx = 1; idx <= n; ++idx) {
        visited.clear();
        if (int n = dfs(idx); n > mx)
            mx = n;
    }
    cout << mx;
}