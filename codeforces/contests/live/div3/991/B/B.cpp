#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int tot = accumulate(a.begin(), a.end(), 0LL);
    if (tot % n) {
        cout << "NO" << endl;
        return;
    }
    int m = tot / n;
    for (int i = 1; i < n - 1; i++) {
        int need = m - a[i - 1];
        a[i - 1] += need;
        a[i + 1] -= need;
    }
    sort(a.begin(), a.end());
    cout << (a[0] == a[n - 1] ? "YES" : "NO") << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
