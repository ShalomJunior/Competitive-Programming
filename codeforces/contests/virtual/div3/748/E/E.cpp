#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<set<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        s.insert({ adj[i].size(), i });
    }
    set<int> ban;
    while (k && !s.empty() && s.begin()->first < 2) {
        set<pair<int, int>> nodes;
        while (!s.empty() && s.begin()->first < 2) {
            auto [z, u] = *s.begin();
            ban.insert(u);
            s.erase(s.begin());
            if (z == 0) continue;
            int v = *adj[u].begin();
            nodes.insert({ v, u });
        }
        set<int> id;
        for (auto it = nodes.begin(); it != nodes.end(); ++it) {
            if (!id.count(it->first)) s.erase({ adj[it->first].size(), it->first });
            adj[it->first].erase(it->second);
            adj[it->second].erase(it->first);
            id.insert(it->first);
        }
        for (auto it = id.begin(); it != id.end(); ++it) {
            int m = adj[*it].size();
            if (!ban.count(*it))s.insert({ m, *it });
        }
        k--;
    }
    cout << s.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}