#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> get(vector<int> a, int k) {
    int n = a.size();
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i += k) {
        if (i + k - 1 < n) {
            ans.push_back({ a[i], a[i + k - 1] });
        }
        else {
            ans.push_back({ a[i], a[n - 1] });
            break;
        }
    }
    for (auto& [l, r] : ans) {
        if (l > r) swap(l, r);
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (auto& c : x) cin >> c;
    sort(x.begin(), x.end());
    long long ans = 1e18;
    for (int i : {1, 2}) {
        auto seg = get(x, k);
        int m = seg.size();
        long long curr = 0;
        for (int i = 0; i < m; i++) {
            auto [l, r] = seg[i];
            int add = 0;
            if (r <= 0) add = -l;
            else if (l >= 0) add += r;
            else add = r - l + min(-l, r);
            curr += add;
            if (i == m - 1) continue;
            if (r <= 0 || l >= 0) curr += add;
            else curr += max(-l, r);
        }
        ans = min(ans, curr);
        reverse(x.begin(), x.end());
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}