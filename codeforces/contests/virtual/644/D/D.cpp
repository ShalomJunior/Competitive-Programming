#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    if (n * a != m * b) { cout << "NO" << endl; return; }

    vector<vector<int>> ans(n, vector<int>(m, 0));
    queue<int> q;
    for (int i = 0; i < m; i++) q.push(i);

    int cum[m]; memset(cum, 0, sizeof(cum));
    int cnt = n * a, i = 0;
    while (cnt) {
        int j = 0;
        while (j++ < a) {
            int f = q.front(); q.pop();
            ans[i][f] = 1;
            q.push(f);
            cum[f]++;
        }
        ++i;
        cnt -= a;
    }
    for (int j = 0; j < m;j++) {
        if (cum[j] != b) { cout << "NO" << endl; return; }
    }
    cout << "YES" << endl;
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}