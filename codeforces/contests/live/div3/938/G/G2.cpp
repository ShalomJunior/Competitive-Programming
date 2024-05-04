#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int g = __gcd(a[0][0], a[n - 1][m - 1]);
    vector<int> divs;
    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            divs.push_back(i);
            if (i * i != g) divs.push_back(g / i);
        }
    }
    auto id = [&](int i, int j) {
        if (0 <= i && i < n && 0 <= j && j < m) return i * m + j;
        return INF;
        };
    sort(divs.rbegin(), divs.rend());
    for (auto& k : divs) {
        auto bfs = [&](int root) {
            vector<bool> vis(n * m);
            queue<int> q;
            q.push(root);
            vis[root] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == id(n - 1, m - 1)) return true;
                int l = u / m;
                int r = u % m;
                if (id(l + 1, r) != INF && a[l + 1][r] % k == 0) {
                    if (!vis[id(l + 1, r)]) {
                        q.push(id(l + 1, r));
                        vis[id(l + 1, r)] = true;
                    }
                }
                if (id(l, r + 1) != INF && a[l][r + 1] % k == 0) {
                    if (!vis[id(l, r + 1)]) {
                        q.push(id(l, r + 1));
                        vis[id(l, r + 1)] = true;
                    }
                }
            }
            return false;
            };
        if (bfs(0)) {
            cout << k << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
