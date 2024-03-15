#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    vector<int> id;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') id.push_back(i);
    }
    int z = id.size();
    if (!z) {
        cout << s << endl;
        return;
    }
    vector<int> cost(z + 1);
    for (int i = 1; i <= z; i++) {
        cost[i] = cost[i - 1] + abs(id[i - 1] - (i - 1));
    }
    if (cost.back() <= k) {
        sort(s.begin(), s.end());
        cout << s << endl;
        return;
    }
    int i;
    for (i = 1; i <= z; i++) {
        if (cost[i] > k) break;
    }
    k -= cost[i - 1];
    string ans(i - 1, '0');
    int j = id[i - 1] - k;
    while (ans.size() < j) ans += '1';
    ans += '0';
    while (k--) ans += '1';
    for (int i = ans.size(); i < n; i++) ans += s[i];
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}