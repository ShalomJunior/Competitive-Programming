#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(n);
    for (auto& [l, r] : a) cin >> l >> r;
    sort(a.begin(), a.end());
    multiset<int> in;
    vector<int> cnt(m + 1);
    for (int i = 1, j = 0; i <= m; i++) {
        while (j < n && a[j].first <= i) {
            in.insert(a[j].second);
            j++;
        }
        cnt[i] = in.size();
        while (!in.empty() && *in.begin() <= i) {
            in.erase(in.begin());
        }
    }
    vector<int> pref(m + 1);
    for (int i = 1; i <= m; i++) {
        pref[i] = pref[i - 1] + cnt[i];
    }
    int ans = -1;
    int noise = INF;
    for (int i = 1; i + k - 1 <= m; i++) {
        int sum = pref[i + k - 1] - pref[i - 1];
        if (sum < noise) {
            noise = sum;
            ans = i;
        }
    }
    cout << ans << ' ' << noise << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}