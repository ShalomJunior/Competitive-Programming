#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 3);
    vector<int> idx;
    for (int i = 0; i < x; i++) {
        int p; cin >> p;
        a[p] = true;
        idx.push_back(p);
    }
    a[0] = a[n - 1];
    a[n + 1] = a[0];
    int ans = 0;
    set<pair<int, int>> db;
    for (int i = 1; i <= n; i++) {
        cerr << i << " " << ans << endl;
        if (a[i]) {
            if (a[i - 1]) {
                auto it = upper_bound(idx.begin(), idx.end(), i);
                if (it != idx.end()) {
                    ans++;
                }
            }
        }
        else {
            if (a[i - 1] && a[i + 1])ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}