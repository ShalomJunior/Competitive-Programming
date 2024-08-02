#include <bits/stdc++.h>
using namespace std;

const int N = 26;
const int M = 50;

struct info {
    int c;
    int p;
    int id;
    set<int> dx;
};

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> adj(N);
    for (int i = 0; i + 1 < n; i++) {
        int u = s[i] - 'a';
        int v = s[i + 1] - 'a';
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (auto& vec : adj) {
        sort(vec.begin(), vec.end());
        vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
        int m = vec.size();
        if (m > 2) {
            cout << "NO" << endl;
            return;
        }
    }
    vector<pair<int, int>> p;
    queue<info> q;
    vector<bool> vis(N);
    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        q.push({ i, -1, i * M , {-1, 1} });
        while (!q.empty()) {
            auto [c, r, id, dx] = q.front();
            q.pop();
            if (vis[c]) continue;
            vis[c] = true;
            p.push_back({ id, c });
            for (auto& neb : adj[c]) {
                if (vis[neb]) {
                    if (neb != r) {
                        cout << "NO" << endl;
                        return;
                    }
                }
                else {
                    int d = *dx.begin();
                    set<int> ndx = { -1, 1 };
                    ndx.erase(d == 1 ? -1 : 1);
                    q.push({ neb, c, id + d, ndx });
                    dx.erase(dx.begin());
                }
            }
        }
    }
    cout << "YES" << endl;
    sort(p.begin(), p.end());
    for (auto& e : p) cout << char('a' + e.second);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
