#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> edges;
    vector<set<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    set<pair<int, int>> deg;
    map<int, int> h;
    auto get = [&](int id) {
        int res = *adj[id].begin();
        adj[id].erase(adj[id].begin());
        edges.erase({ id, res });
        edges.erase({ res, id });
        return res;
        };
    auto update = [&](int id, int z) {
        deg.erase({ h[id], id });
        h[id] += z;
        if (h[id]) deg.insert({ h[id], id });
        };
    for (int i = 0; i < n; i++) {
        deg.insert({ adj[i].size(), i });
        h[i] = adj[i].size();
    }
    int k = 0;
    stringstream ss;
    cerr << "start" << endl;
    while (!deg.empty()) {
        auto [cnt, id] = *prev(deg.end());
        cerr << "id " << id << endl;
        update(id, -2);
        cerr << "nnoway" << endl;
        if (cnt < 2) break;
        int u = get(id);
        int v = get(id);
        k++;
        ss << id + 1 << " " << u + 1 << " " << v + 1 << endl;
        cerr << "hell" << endl;
        if (edges.count({ u, v })) {
            edges.erase({ u, v });
            update(u, -1);
            update(v, -1);
        }
        else if (edges.count({ v, u })) {
            edges.erase({ v, u });
            update(u, -1);
            update(v, -1);
        }
        else {
            edges.insert({ u, v });
            update(u, 1);
            update(v, 1);
        }
    }
    cerr << "finished" << endl;
    for (auto& [l, r] : edges) cerr << l << " " << r << endl;
    int z = edges.size();
    auto [boss, last] = *edges.begin();
    set<int> p;
    for (int i = 0; i < n; i++) p.insert(i);
    cerr << "finished2" << endl;

    cerr << "going" << endl;
    cerr << edges.size() << endl;
    if (edges.size()) {
        for (auto it = next(edges.begin()); it != edges.end(); it++) {
            cerr << "in" << endl;
            auto [l, r] = *it;
            cerr << l << " " << r << " " << edges.size() << endl;
            p.erase(l);
            p.erase(r);
            update(boss, 2);
            update(l, -1);
            update(r, -1);
            k++;
            ss << boss + 1 << " " << l + 1 << " " << r + 1 << endl;
        }
    }
    cerr << "fucking" << endl;
    for (auto& c : p) {
        k++;
        ss << boss + 1 << " " << last + 1 << " " << c + 1 << endl;
    }
    cerr << "ednd" << endl;
    cout << k << endl;
    cout << ss.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
