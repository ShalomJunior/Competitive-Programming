#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, p;
    cin >> n >> p;
    vector<pair<int, int>> a(p + 1);
    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        a[i].first = u - 1;
        a[i].second = v - 1;
    }
    string s;
    cin >> s;
    vector<int> order;
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        int l = a[r].first;
        int r = a[r].second;
        if (s[r] == 'L') {
            if (!vis[l]) dfs(l);
            if (!vis[l]) dfs(r);
        }
        else {
            if (!vis[l]) dfs(r);
            if (!vis[l]) dfs(l);
        }
        order.push_back(r);
        };
    reverse(order.begin(), order.end());
    dfs(0);
    vector<int> cnt(p + 1);
    vector<bool> vis(p + 1);
    cnt[0] = n;
    for (int i = 0; i < p; i++) {
        int l = a[i].first;
        int r = a[i].second;
        cnt[l] += cnt[i] / 2;
        cnt[r] += cnt[i] / 2;
        if (cnt[i] & 1) {
            s[i] == 'L' ? cnt[l]++ : cnt[r]++;
        }
    }
    for (int i = 0; i < p; i++) {
        if (cnt[i] & 1) {
            cout << (s[i] == 'L' ? 'R' : 'L');
        }
        else {
            cout << s[i];
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}


/*
    vector<int> order;
    function<void(int)> dfs = [&](int r) {
        vis[r] = true;
        int l = a[r].first;
        int r = a[r].second;
        if (s[r] == 'L') {
            if (!vis[l]) dfs(l);
            if (!vis[l]) dfs(r);
        }
        else {
            if (!vis[l]) dfs(r);
            if (!vis[l]) dfs(l);
        }
        order.push_back(r);
    };
    reverse(order.begin(), order.end());
    dfs(0);
*/

// #include <bits/stdc++.h>
// using namespace std;

// void solve() {
//     int n, p;
//     cin >> n >> p;
//     vector<pair<int, int>> a(p + 1);
//     map<pair<int, int>, int> h;
//     vector<int> in(p + 1);
//     for (int i = 0; i < p; i++) {
//         int u, v;
//         cin >> u >> v;
//         --u, --v;
//         a[i].first = u;
//         a[i].second = v;
//         in[u]++;
//         in[v]++;
//         if (u != p)h[{min(i, u), max(i, u)}]++;
//         if (v != p)h[{min(i, v), max(i, v)}]++;
//     }
//     int mx = 0;
//     for (auto& [p, val] : h) {
//         mx = max(mx, val);
//     }
//     assert(mx <= 1);
//     string s;
//     cin >> s;
//     vector<int> cnt(p + 1);
//     vector<bool> vis(p + 1);
//     auto bfs = [&](int root) {
//         queue<int> q;
//         q.push(root);
//         cnt[root] = n;
//         while (!q.empty()) {
//             int u = q.front();
//             q.pop();
//             if (vis[u]) continue;
//             vis[u] = true;
//             int l = a[u].first;
//             int r = a[u].second;
//             cnt[l] += cnt[u] / 2;
//             cnt[r] += cnt[u] / 2;
//             if (cnt[u] & 1) {
//                 s[u] == 'L' ? cnt[l]++ : cnt[r]++;
//             }
//             in[l]--;
//             in[r]--;
//             if (l != p && in[l] == 0) q.push(l);
//             if (r != p && in[r] == 0) q.push(r);
//         }
//         };
//     bfs(0);
//     int tot = 0;
//     for (int i = 0; i < p; i++)tot += vis[i];
//     for (int i = 0; i < p; i++) {
//         if (cnt[i] & 1) {
//             cout << (s[i] == 'L' ? 'R' : 'L');
//         }
//         else {
//             cout << s[i];
//         }
//     }
//     cout << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     solve();
// }