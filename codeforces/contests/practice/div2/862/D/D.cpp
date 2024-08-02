#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    vector<bool> vis(n);
    vector<int> par(n);
    vector<int> depth(n);
    vector<int> far(n);
    function<void(int, bool)> dfs = [&](int r, bool flag) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                par[c] = r;
                depth[c] = depth[r] + 1;
                if (flag) far[c] = far[r] + 1;
                dfs(c, flag);
            }
        }
        };
    dfs(0, false);
    int root = max_element(depth.begin(), depth.end()) - depth.begin();
    vis = vector<bool>(n);
    par[root] = root;
    assert(count(vis.begin(), vis.end(), false) == n);
    dfs(root, false);
    int end = max_element(depth.begin(), depth.end()) - depth.begin();
    vector<int> order;
    int x = end;
    while (x != root) {
        order.push_back(x);
        x = par[x];
    }
    order.push_back(x);
    int len = order.size();
    vis = vector<bool>(n);
    for (int i = 0; i < len; ++i) {
        far[order[i]] = max(i, len - (i + 1));
        vis[order[i]] = true;
    }
    for (auto& r : order) dfs(r, true);
    vector<int> cnt(n + 1);
    for (auto& c : far) cnt[c]++;
    int tot = accumulate(cnt.begin(), cnt.end(), 0);
    for (int i = 1; i <= n; i++) {
        cout << min(n - tot + 1, n) << " ";
        tot -= cnt[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

/*

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    vector<bool> vis(n);
    vector<int> par(n);
    vector<int> depth(n);
    vector<int> far(n);
    function<void(int, bool)> dfs = [&](int r, bool flag) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            cerr << r << "-> " << c << endl;
            if (!vis[c]) {
                cerr << "in" << endl;
                par[c] = r;
                depth[c] = depth[r] + 1;
                if (flag) far[c] = far[r] + 1;
                dfs(c, flag);
            }
        }
        };
    dfs(0, false);
    int root = max_element(depth.begin(), depth.end()) - depth.begin();
    vis = vector<bool>(n);
    par[root] = root;
    cerr << endl;
    assert(count(vis.begin(), vis.end(), false) == n);
    dfs(root, false);
    int end = max_element(depth.begin(), depth.end()) - depth.begin();
    vector<int> order;
    int x = end;
    while (x != root) {
        order.push_back(x);
        x = par[x];
    }
    cerr << root << " | " << end << endl;
    order.push_back(x);
    for (auto& c : order) cerr << c << " -> ";
    cerr << endl;
    int len = order.size();
    vis = vector<bool>(n);
    for (int i = 0; i < len; ++i) {
        far[order[i]] = max(i, len - (i + 1));
        vis[order[i]] = true;
    }
    for (auto& r : order) dfs(r, true);
    for (auto& c : far) cerr << c << " ";
    cerr << "#" << endl;
    vector<int> cnt(n + 1);
    for (auto& c : far) cnt[c]++;
    int tot = accumulate(cnt.begin(), cnt.end(), 0);
    cerr << "tot = " << tot << endl;
    for (int i = 1; i <= n; i++) {
        cout << min(n - tot + 1, n) << " ";
        tot -= cnt[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}*/