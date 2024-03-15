#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> f, p;
vector<vector<int>> adj;


void solve() {
    cin >> n >> k;

    f.resize(n + 1);
    for (auto& c : f)cin >> c;

    p.resize(n + 1);
    adj.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        adj.clear();
        solve();
    }
}