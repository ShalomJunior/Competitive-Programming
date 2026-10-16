#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int len = set<int>(a.begin(), a.end()).size();
    if (len > k) {
        cout << -1 << endl;
        return;
    }
    int r = k - len;
    set<int> s;
    vector<int> ans;
    for (auto& c : a) {
        if (s.count(c)) {
            if (r > 0) {
                ans.push_back(c);
                r--;
            }
        }
        else {
            ans.push_back(c);
        }
        s.insert(ans.back());
    }
    int j = 0;
    for (int i = 0; i < n;) {
        int z = ans.size();
        if (j == z) ans.push_back(ans[j % k]);
        if (a[i] == ans[j]) i++;
        j++;
    }
    cout << ans.size() << endl;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}