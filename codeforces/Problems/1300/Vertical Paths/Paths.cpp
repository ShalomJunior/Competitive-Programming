#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

stringstream out, ss;
vector<priority_queue<pair<int, int>>> adj2;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> dis;
multiset<pair<int, int>> ms;

void dbg(int r) {
    cout << "dbg : " << r << endl;
}

int dfs(int r) {
    vis[r] = true;
    int mx = 0;
    for (auto& c : adj[r]) {
        if (!vis[c]) {
            mx = max(mx, dfs(c));
        }
    }
    dis[r] = ++mx;
    return mx;
}

int dfs2(int r) {
    int ans = 1;
    ss << r << " ";
    vis[r] = true;
    if (!adj2[r].empty()) {
        auto tp = adj2[r].top();
        ans += dfs2(tp.second);
        adj2[r].pop();
    }
    ms.erase(mp(dis[r], r));
    return ans;
}

void solve() {
    int n; cin >> n;

    vector<int> v(n + 1);
    adj.resize(n + 1);
    vis.resize(n + 1);
    dis.resize(n + 1);
    int root;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        adj[i].push_back(v[i]);
        adj[v[i]].push_back(i);
        if (i == v[i])root = i;
    }

    dfs(root);
    adj2.resize(n + 1);
    for (int i = 1; i <= n;i++) {
        auto p = mp(dis[i], i);
        ms.insert(p);
        if (i != root)
            adj2[v[i]].push(p);
    }

    int mn = 0;
    vis = vector<bool>(n + 1);
    while (!ms.empty()) {
        mn++;
        auto pr = *prev(ms.end());
        ss = stringstream();
        int ver = dfs2(pr.second);
        out << ver << endl;
        out << ss.str() << endl;
    }
    cout << mn << endl;
    cout << out.str() << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        adj.clear(); adj2.clear();
        vis.clear(); dis.clear();
        ms.clear();
        out = stringstream();
        solve();
    }
}