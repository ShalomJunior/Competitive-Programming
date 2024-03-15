#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int cnt = 0, last = a[0], M = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] - last <= k) cnt++, last = a[i];
        if (a[i] - last > k) {
            M = max(M, cnt);
            cnt = 1; last = a[i];
        }
        if (i == n - 1) { M = max(M, cnt); }
    }
    cout << n - M << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}