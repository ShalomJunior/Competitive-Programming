#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        ans = max(ans, min(a[i], a[i + 1]));
    }
    for (int i = 0; i + 2 < n; i++) {
        vector<int> v = { a[i], a[i + 1], a[i + 2] };
        sort(v.begin(), v.end());
        ans = max(ans, v[1]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
