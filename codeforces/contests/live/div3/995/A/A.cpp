#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(n);
    for (auto& c : b) cin >> c;
    int ans = a[n - 1];
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] > b[i + 1]) {
            ans += a[i] - b[i + 1];
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
