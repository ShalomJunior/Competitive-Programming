#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int tot = accumulate(a.begin(), a.end(), 0);
    vector<int> b(n, tot / n);
    for (int i = 0; i < tot % n; i++) b[i]++;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] > a[i]) ans += b[i] - a[i];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}