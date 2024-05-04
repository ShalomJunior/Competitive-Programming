#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n - 1);
    map<int, int> cnt;
    int sup = 0, M = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
        int d = a[i] - (i ? a[i - 1] : 0);
        if (d > n) sup++;
        cnt[d]++;
        M = max(M, cnt[d]);
    }
    int h = 0;
    for (int i = 1; i <= n; i++) {
        if (!cnt.count(i)) h++;
    }
    if (h == 1) { cout << "YES" << endl; return; }
    if (sup > 1) { cout << "NO" << endl; return; }
    else if (sup == 1) {
        vector<int> x;
        for (int i = 1; i <= n; i++) {
            if (!cnt.count(i)) x.push_back(i);
        }
        if (x.size() != 2) { cout << "NO" << endl; return; }
        for (int i = 0; i < n - 1; i++) {
            int d = a[i] - (i ? a[i - 1] : 0);
            if (d <= n) continue;
            cout << (x[0] + x[1] == d ? "YES" : "NO") << endl;
            return;
        }
    }
    else {
        if (M != 2) { cout << "NO" << endl; return; }
        int nb = 0, id;
        for (auto& [k, v] : cnt) {
            if (v == M) id = k, nb++;
        }
        if (nb != 1) { cout << "NO" << endl; return; }
        vector<int> x;
        for (int i = 1; i <= n; i++) {
            if (!cnt.count(i)) x.push_back(i);
        }
        if (x.size() != 2) { cout << "NO" << endl; return; }
        for (int i = 0; i < n - 1; i++) {
            int d = a[i] - (i ? a[i - 1] : 0);
            if (d != id) continue;
            if (x[0] + x[1] == d) { cout << "YES" << endl; return; }
        }
    }
    cout << "NO" << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}