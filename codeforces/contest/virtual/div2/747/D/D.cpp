#include <bits/stdc++.h>
using namespace std;

class dsu {
public:
    vector<int> parents;
    vector<int> sizes;
    dsu(int n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        sizes.resize(n, 1);
    }
    int root(int u) {
        return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
        int a = root(u);
        int b = root(v);
        if (a == b) return 0;
        if (sizes[a] > sizes[b]) swap(a, b);
        parents[a] = b;
        sizes[b] += sizes[a];
        return 1;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    dsu ds(n);
    vector<vector<vector<pair<int, int>>>> from(2, vector<vector<pair<int, int>>>(n));
    vector<vector<vector<int>>> to(2, vector<vector<int>>(n));
    for (int i = 0; i < k; i++) {
        int a, b; string s;
        cin >> a >> b >> s;
        --a, --b;
        int w = (s == "imposter");
        from[0][a].push_back(make_pair(b, w));
        from[1][a].push_back(make_pair(b, w ^ 1));
        to[w][b].push_back(a);
        ds.join(a, b);
    }
    for (auto& c : ds.parents) c = ds.root(c);
    auto roots = ds.parents;
    sort(roots.begin(), roots.end());
    roots.resize(unique(roots.begin(), roots.end()) - roots.begin());
    int m = roots.size();
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        if (ds.sizes[roots[i]] == 1) {
            ans[i] = 1;
            continue;
        }
        auto bfs = [&](int state) {
            unordered_map<int, int> h;
            queue<pair<int, int>> q;
            h[roots[i]] = state;
            q.push({ roots[i], state });
            while (!q.empty()) {
                auto [u, w] = q.front();
                q.pop();
                for (auto [v, ww] : from[w][u]) {
                    if (h.count(v)) {
                        if (h[v] != ww) return -1;
                    }
                    else {
                        h[v] = ww;
                        q.push({ v, ww });
                    }
                }
                for (int j : {0, 1}) {
                    for (auto& c : to[j][u]) {
                        if (j == w) {
                            if (h.count(c)) {
                                if (h[c] != 0) return -1;
                            }
                            else {
                                h[c] = 0;
                                q.push({ c, 0 });
                            }
                        }
                        else {
                            if (h.count(c)) {
                                if (h[c] != 1) return -1;
                            }
                            else {
                                h[c] = 1;
                                q.push({ c, 1 });
                            }
                        }
                    }
                }
            }
            int cnt = 0;
            for (auto& [_, v] : h) {
                if (v == 1) cnt++;
            }
            return cnt;
            };
        ans[i] = max(bfs(0), bfs(1));
    }
    cout << (count(ans.begin(), ans.end(), -1) ? -1 : accumulate(ans.begin(), ans.end(), 0)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}