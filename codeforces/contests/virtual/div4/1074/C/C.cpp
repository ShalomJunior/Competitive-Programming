#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = a.size();
    int ans = 1;
    int len = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1) {
            len++;
        }
        else {
            ans = max(ans, len);
            len = 1;
        }
    }
    ans = max(ans, len);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}