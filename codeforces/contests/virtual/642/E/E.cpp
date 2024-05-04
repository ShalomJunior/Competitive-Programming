#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    vector<int> cnt(k);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') cnt[i % k]++;
    }
    int on = count(s.begin(), s.end(), '1');
    if (!on) {
        cout << 0 << endl;
        return;
    }
    int ans = 1e9;
    for (int i = 0; i < k; i++) {
        int q = (n - 1 - i) / k + 1;
        ans = min(ans, q - cnt[i] + on - cnt[i]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}