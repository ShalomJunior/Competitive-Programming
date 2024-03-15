#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    int am = *min_element(a.begin(), a.end());
    int bm = *min_element(b.begin(), b.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int da = abs(a[i] - am);
        int db = abs(b[i] - bm);
        ans += max(da, db);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}