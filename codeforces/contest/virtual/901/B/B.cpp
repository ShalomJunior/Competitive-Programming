#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long tot = accumulate(a.begin(), a.end(), 0LL);
    if (a[0] >= b[m - 1]) {
        if (k & 1) cout << tot;
        else cout << tot - a[n - 1] + b[0];
        cout << endl;
    }
    else {
        tot += b[m - 1] - a[0];
        if (k & 1) cout << tot;
        else cout << tot - max(a[n - 1], b[m - 1]) + min(a[0], b[0]);
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}