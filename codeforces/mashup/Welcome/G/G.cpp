#include <bits/stdc++.h>

using namespace std;

bool trap;
int room, deep;
vector<bool> visited;
vector<vector<int>> corr;

void dfs(int t, int cnt) {
    cnt++;
    visited[t] = true;
    for (auto& c : corr[t]) {
        if (visited[c])continue;
        dfs(c, cnt);
    }

    if (cnt == deep) trap = true;
    else if (cnt > deep) {
        trap = false;
        deep = cnt;
        room = t;
    }
}

void solve() {
    int n; cin >> n;

    visited.resize(n + 1);
    corr.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        corr[a].push_back(b);
        corr[b].push_back(a);
    }

    dfs(1, 0);
    cout << ((trap) ? "it was a trap!" : to_string(room)) << endl;
}

int main() {
    freopen("azuz.in", "r", stdin);
    int t; cin >> t;
    while (t--) {
        trap = false;
        room = 1; deep = 0;
        visited = vector<bool>();
        corr = vector<vector<int>>();
        solve();
    }
}