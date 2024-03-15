#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;  int k;
    cin >> s >> k;
    int n = s.size();
    int last = -1;
    vector<vector<int>> a(10);
    for (int i = 0; i < n; i++) {
        a[s[i] - '0'].push_back(i);
        if (s[i] != '0')last = i;
    }
    string ans = "";
    int i = 0;
    while (k && i < n) {
        for (int d = 0; d < 10; d++) {
            if (!i && !d)continue;
            auto it = lower_bound(a[d].begin(), a[d].end(), i);
            if (it == a[d].end() || (it != a[d].end() && *it > i + k)) continue;
            if (last < *it) k--;
            else {
                ans += ('0' + d);
                k -= (*it - i);
            }
            i = *it + 1;
            break;
        }
    }
    cout << i << "->" << n << endl;
    ans += s.substr(i, n - i);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}