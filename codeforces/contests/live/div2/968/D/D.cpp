#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        a[i].resize(l);
        for (int j = 0; j < l; j++) cin >> a[i][j];
    }
    int mx = 0;
    vector<int> mis(n);
    vector<int> top(n);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++) {
        int k = a[i].size();
        sort(a[i].begin(), a[i].end());
        mx = max(mx, k);
        bool f = true;
        mis[i] = k;
        top[i] = k;
        for (int j = 0; j < k; j++) {
            if (a[i][j] != j) {
                if (f) {
                    mis[i] = j;
                    f = false;
                }
                else {
                    top[i] = j;
                }
            }
        }
        if (mis[i] < n) adj[mis[i]].push_back(i);
    }
    queue<int> q;
    vector<bool> vis(n);
    vector<int> score(n);
    function<void(int, int&)> dfs = [&](int r, int res) {
        if (r == n) {
            res = n;
            return;
        }
        q.push(r);
        vis[r] = true;
        for (auto& c : adj[r]) {
            if (vis[c]) {
                res = max(res, score[c]);
            }
            else {
                res = max(res, top[c]);
                dfs(top[c], res);
            }
        }
        };
    for (int i = 0; i < n; i++) {
        cerr << "mis = " << mis[i] << endl;
        if (mis[i] < n && !vis[mis[i]]) {
            int res = 0;
            dfs(mis[i], res);
            cerr << "RES = " << res << endl;
            while (!q.empty()) {
                score[q.front()] = res;
                q.pop();
            }
        }
    }
    set<int> in(mis.begin(), mis.end());
    cerr << "FINISIH" << endl;
    int K = *max_element(score.begin(), score.end());
    cerr << "-> " << K << endl;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (i >= mx) {
            ans += i;
        }
        else {
            if (in.count())
                cerr << "in" << endl;
            int res = 0;
            dfs(i, res);
            ans += max(i, score[i]);
            cerr << "out" << endl;

        }
    }
    cout << ans << endl;
    cerr << "END" << endl;
    cerr << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
