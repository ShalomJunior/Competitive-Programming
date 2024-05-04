#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), h;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) h.push_back(abs(a[i] - a[i - 1]));
    }
    sort(h.begin(), h.end());
    int ans = 0;
    for (int i = 0; i < n - k; i++) {
        ans += h[i];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}