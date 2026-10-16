#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> m(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i] >> p[i];
    }
    vector<int> om(n);
    iota(om.begin(), om.end(), 0);
    sort(om.begin(), om.end(), [&](const int& i, const int& j) {
        return m[i] < m[j];
        });
    vector<int> op(n);
    iota(op.begin(), op.end(), 0);
    sort(op.begin(), op.end(), [&](const int& i, const int& j) {
        return p[i] < p[j];
        });
    int im = 0;
    int ip = 0;
    int cost = 0;
    int cnt = 0;
    vector<bool> done(n);
    while (cnt < n) {
        while (im < n && m[om[im]] <= cnt) {
            if (!done[om[im]]) {
                done[om[im]] = true;
                cnt++;
            }
            im++;
        }
        while (ip < n && done[op[ip]]) ip++;
        if (cnt == n) break;
        int id = op[ip];
        cost += p[id];
        done[id] = true;
        cnt++;
    }
    cout << cost << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
