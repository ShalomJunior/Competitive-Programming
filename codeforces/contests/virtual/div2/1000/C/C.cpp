#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        cnt[u]++;
        cnt[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> p(n);
    vector<bool> vis(n);
    vector<int> child(n);
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                p[c] = r;
                dfs(c);
                child[r]++;
            }
        }
        };
    dfs(0);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int r = p[i];
        ans = max(ans, child[i] + cnt[r] - 1);
    }
    multiset<int> ms(cnt.begin(), cnt.end());
    for (int i = 0; i < n; i++) {
        int curr = cnt[i];
        ms.erase(ms.find(cnt[i]));
        for (auto& c : adj[i]) ms.erase(ms.find(cnt[c]));
        if (!ms.empty()) {
            curr += *prev(ms.end()) - 1;
            ans = max(ans, curr);
        }
        for (auto& c : adj[i]) ms.insert(cnt[c]);
        ms.insert(cnt[i]);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}


/*

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        cnt[u]++;
        cnt[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> p(n);
    vector<bool> vis(n);
    vector<int> child(n);
    function<void(int) > dfs = [&](int r) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                p[c] = r;
                dfs(c);
                child[r]++;
            }
        }
        };
    dfs(0);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int r = p[i];
        ans = max(ans, child[i] + child[r] - 1);
    }
    cerr << "ans# " << ans << endl;
    multiset<int> ms(cnt.begin(), cnt.end());
    for (int i = 0; i < n; i++) {
        int curr = cnt[i] - 1;
        ms.erase(ms.find(cnt[i]));
        for (auto& c : adj[i]) {
            ms.erase(ms.find(cnt[c]));
        }
        cerr << "sz = " << i << " " << ms.size() << endl;
        if (!ms.empty()) {
            curr += *prev(ms.end());
            ans = max(ans, curr);
        }
        for (auto& c : adj[i]) {
            ms.insert(cnt[c]);
        }
        ms.insert(cnt[i]);
    }
    cout << ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
*/