#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (auto& c : x) cin >> c;
    map<int, int> cnt;
    for (int i = 1; i < n; i++) {
        int m = x[i] - x[i - 1] - 1;
        cnt[i * (n - i)] += m;
    }
    cnt[n - 1]++;
    if (n > 1) cnt[n - 1]++;
    for (int i = 1; i + 1 < n; i++) {
        cnt[i * (n - i) + (n - 1 - i)]++;
    }
    while (q--) {
        int k;
        cin >> k;
        cout << cnt[k] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
