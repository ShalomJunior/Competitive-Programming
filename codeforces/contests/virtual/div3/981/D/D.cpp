#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    vector<int> ans(n + 1);
    map<int, int> id;
    id[0] = 0;
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1];
        if (id.count(pref[i])) {
            int p = id[pref[i]];
            ans[i] = max(ans[i], 1 + ans[p]);
        }
        id[pref[i]] = i;
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}