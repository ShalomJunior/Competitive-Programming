#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    if (k == 1) { cout << 0 << endl; return; }
    set<string> vis;
    queue<string> q;
    int ans = 0;
    auto Bfs = [&](string t) {
        int m = t.length();
        for (int i = 0; i < m; i++) {
            string child = t.substr(0, i) + (i != m - 1 ? t.substr(i + 1, n - i - 1) : "");
            if (!vis.count(child)) {
                q.push(child);
                vis.insert(child);
                ans += n - m + 1;
            }
            if (vis.size() == k) return true;
        }
        return false;
        };
    q.push(s);
    vis.insert(s);
    while (!q.empty()) {
        bool b = Bfs(q.front());
        if (Bfs(q.front())) {
            cout << ans << endl;
            return;
        }
        q.pop();
    };
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}