#include <bits/stdc++.h>
using namespace std;

void g(vector<int>& v) { sort(v.begin(), v.end()); }

void solve() {
    int n, k; cin >> n >> k;
    vector<int> t(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i] >> b[i];
    }
    vector<int> both, f, s;
    for (int i = 0; i < n; i++) {
        if (a[i] && b[i]) both.push_back(t[i]);
        else if (a[i]) f.push_back(t[i]);
        else if (b[i]) s.push_back(t[i]);
    }
    int m = min(f.size(), s.size());
    if (both.size() + m < k) {
        cout << -1 << endl;
        return;
    }
    g(f); g(s);
    for (int i = 0; i < m; i++) {
        both.push_back(f[i] + s[i]);
    }
    g(both);
    int ans = accumulate(both.begin(), both.begin() + k, 0);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
