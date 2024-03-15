#include <bits/stdc++.h>

using namespace std;

bool trap;
int room;
int best;
vector<bool> visited;
vector<vector<int>> adj;

void dfs(int r, int cnt) {
    cnt++;
    visited[r] = true;
    for (auto& c : adj[r]) {
        if (!visited[c])
            dfs(c, cnt);
    }

    if (cnt == best)
        trap = true;
    else if (cnt > best)
        trap = false, best = cnt, room = r;

}
void solve() {
    int n; cin >> n;

    trap = false; room = 1; best = 0;
    adj = vector<vector<int>>(n + 1);
    visited = vector<bool>(n + 1);
    for (int i = 1; i < n;i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    if (trap) cout << "it was a trap!" << endl;
    else cout << room << endl;
}

int main() {
    freopen("azuz.in", "r", stdin);
    int t; cin >> t;
    while (t--)solve();
}