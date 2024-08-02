#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int m;
    cin >> m;
    vector<int> p(max(m, n - 1), 1);
    for (int i = 0; i < m; ++i) cin >> p[i];
    vector<bool> vis(n);
    vector<int> child(n, 1);
    vector<int> w;
    function<void(int, bool)> dfs = [&](int r, bool f) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                dfs(c, f);
                if (f) {
                    w.push_back(child[c] * (n - child[c]));
                }
                if (!f)
                    child[r] += child[c];
            }
        }
        };
    dfs(0, false);
    vis = vector<bool>(n);
    dfs(0, true);
    sort(w.begin(), w.end());
    sort(p.begin(), p.end());
    while (p.size() > n - 1) {
        int z = p.size();
        p[z - 2] *= p[z - 1];
        p[z - 2] %= MOD;
        p.pop_back();
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += (w[i] % MOD) * p[i] % MOD;
        ans %= MOD;
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

const int MOD = 1e9 + 7;
void solve() {
    cerr << endl;
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cerr << "passed" << endl;
    int m;
    cin >> m;
    vector<int> p(max(m, n - 1), 1);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
        cerr << p[i] << " -> ";
    }
    cerr << endl;
    vector<bool> vis(n);
    vector<int> child(n, 1);
    vector<int> w;
    function<void(int, bool)> dfs = [&](int r, bool f) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                dfs(c, f);
                if (f) {
                    cerr << "#" << child[c] << endl;
                    w.push_back(child[c] * (n - child[c]) % MOD);
                }
                if (!f)
                    child[r] += child[c];
            }
        }
        };
    cerr << "passed" << endl;

    dfs(0, false);
    vis = vector<bool>(n);
    dfs(0, true);
    sort(w.begin(), w.end());
    sort(p.begin(), p.end());
    cerr << "passed" << endl;

    while (p.size() > n - 1) {
        int z = p.back();
        cerr << "z = " << z << endl;
        p[z - 2] *= p[z - 1];
        p[z - 2] %= MOD;
        p.pop_back();
    }
    cerr << "passed" << endl;

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        cerr << "i = " << i << endl;
        cerr << w[i] << " " << p[i] << endl;
        ans += w[i] * p[i] % MOD;
        ans %= MOD;
    }
    cerr << "passed" << endl;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}*/

/*
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
void solve() {
    cerr << endl;
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cerr << "apssed" << endl;
    int m;
    cin >> m;
    vector<int> p(n - 1, 1);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (i < n - 1) p[i] = x;
        else {
            p[n - 2] = p[n - 2] * x % MOD;
        }
    }
    cerr << "apssed" << endl;

    vector<bool> vis(n);
    vector<int> child(n, 1);
    vector<int> w;
    function<void(int, bool)> dfs = [&](int r, bool f) {
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (!vis[c]) {
                dfs(c, f);
                if (f) {
                    cerr << "#" << child[c] << endl;
                    w.push_back(child[c] * (n - child[c]) % MOD);
                }
                if (!f)
                    child[r] += child[c];
            }
        }
        };
    dfs(0, false);
    vis = vector<bool>(n);
    dfs(0, true);
    sort(w.begin(), w.end());
    sort(p.begin(), p.end());
    for (auto& c : w) cerr << c << " -> ";
    cerr << endl;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += w[i] * p[i] % MOD;
        ans %= MOD;
    }
    // int M = 1;
    // for (auto& c : p) M = M * c % MOD;
    // ans -= w.back();
    // ans += w.back() * M % MOD;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}*/