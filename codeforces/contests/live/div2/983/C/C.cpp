#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int ans = n - 1;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] + a[i + 1] > a[n - 1]) {
            ans = min(ans, i);
        }
    }
    vector<int> s(n);
    for (int i = 1; i < n; i++) s[i] = a[i] + a[i - 1];
    for (int i = n - 1; i > 0; i--) {
        auto it = upper_bound(s.begin(), s.end(), a[i]);
        int j = it - s.begin();
        ans = min(ans, j - 1 + n - 1 - i);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
