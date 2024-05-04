#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    unordered_map<int, int>h(n);
    map<int, int> rev;

    for (int i = 1; i <= n; i++) {
        h[i] = n - i + 1;
        rev[i] = n - i + 1;
    }

    int mn = 1, mx = n;
    int i, cnt = 0;
    vector<int> ans(n, -1);
    for (i = 1; i <= m; i++) {
        int p; cin >> p;
        if (cnt == n) continue;

        if (h.find(p) != h.end()) {
            rev.erase(h[p]);
        }
        else {
            ans[rev[mn] - 1] = i;
            cnt++;
            h.erase(rev[mn]);
            rev.erase(mn);
        }
        mn = rev.begin()->first;
        h[p] = ++mx;
        rev[mx] = p;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}