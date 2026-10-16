#include <bits/stdc++.h>
#define int long long
using namespace std;

auto brute(vector<int>& a, int m) {
    int n = a.size();
    vector<int> ans;
    for (int i = 0; i < 1 << n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += a[j];
            }
        }
        ans.push_back(sum % m);
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> x, y;
    int i = 0, j = n - 1;
    while (i < j) {
        x.push_back(a[i]);
        y.push_back(a[j]);
        i++, j--;
    }
    if (i == j) x.push_back(a[j]);
    reverse(y.begin(), y.end());
    x = brute(x, m);
    y = brute(y, m);
    int ans = 0;
    for (auto& c : x) {
        int need = m - 1 - c;
        auto it = upper_bound(y.begin(), y.end(), need);
        if (it != y.begin()) {
            it--;
            ans = max(ans, c + *it);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
