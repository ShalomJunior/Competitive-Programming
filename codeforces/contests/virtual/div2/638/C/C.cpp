#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    sort(s.begin(), s.end());
    vector<string> a(k);
    for (int i = 0; i < k; i++) a[i] += s[i];
    a[0] += s.substr(k, n - k);
    string ans = max(a[0], a[k - 1]);
    while (k > 1 && (int)a[0].size() > k - 1) {
        for (int j = 1; j < k; j++) {
            a[j] += a[0].back();
            a[0].pop_back();
        }
        string curr = *max_element(a.begin(), a.end());
        if (curr > ans) break;
        ans = curr;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
