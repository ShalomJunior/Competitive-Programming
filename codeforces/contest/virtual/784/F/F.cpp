#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), p(n), s(n);
    for (int i = 0;i < n; i++) {
        cin >> a[i];
        p[i] = a[i] + ((i) ? p[i - 1] : 0);
    }

    for (int i = n - 1; i >= 0; i--) {
        s[i] = a[i] + ((i == n - 1) ? 0 : s[i + 1]);
    }
    reverse(s.begin(), s.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(s.begin(), s.end(), p[i]);
        if (it == s.end())break;
        else if (*it != p[i])continue;
        int j = n - 1 - (it - s.begin());
        if (*it == p[i] && i < j)ans = max(ans, i + 1 + n - j);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}