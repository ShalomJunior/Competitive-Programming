#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> ans(n);
    vector<int> sum(n);
    vector<int> mx(n, 1);
    vector<bool> vis(n);
    vector<map<int, int>> cnt(n);
    auto merge = [&](int root, int child) {
        auto& a = cnt[root];
        auto& b = cnt[child];
        int n = a.size();
        int m = b.size();
        if (n < m) {
            swap(a, b);
            swap(sum[root], sum[child]);
            swap(mx[root], mx[child]);
        }
        for (auto& [k, v] : b) {
            a[k] += v;
            if (a[k] > mx[root]) {
                mx[root] = a[k];
                sum[root] = k;
            }
            else if (a[k] == mx[root]) {
                sum[root] += k;
            }
        }
        };
    function<void(int)> dfs = [&](int root) {
        vis[root] = true;
        sum[root] = c[root];
        cnt[root][c[root]] = 1;
        for (auto& child : adj[root]) {
            if (!vis[child]) {
                dfs(child);
                merge(root, child);
            }
        }
        ans[root] = sum[root];
        };
    dfs(0);
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}


/*
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> ans(n);
    vector<bool> vis(n);
    vector<map<int, int>> cnt(n);
    vector<int> sum(n);
    vector<int> mx(n, 1);
    auto merge = [&](int root, int child) {
        cerr << "root: " << root << endl;
        auto& a = cnt[root];
        auto& b = cnt[child];
        int n = a.size();
        int m = b.size();
        if (n < m) {
            swap(a, b);
            swap(sum[root], sum[child]);
            swap(mx[root], mx[child]);
        }
        for (auto& [k, v] : b) {
            cerr << "k : " << k << endl;
            a[k] += v;
            if (a[k] > mx[root]) {
                mx[root] = a[k];
                sum[root] = k;
            }
            else if (a[k] == mx[root]) {
                cerr << "adding " << k << " " << a[k] << endl;
                sum[root] += k;
            }
            cerr << "sum " << sum[root] << endl;
        }
        cerr << endl;
        };
    function<void(int)> dfs = [&](int root) {
        vis[root] = true;
        sum[root] = c[root];
        cnt[root][c[root]] = 1;
        for (auto& child : adj[root]) {
            if (!vis[child]) {
                dfs(child);
                merge(root, child);
            }
        }
        ans[root] = sum[root];
        };
    dfs(0);
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
*/