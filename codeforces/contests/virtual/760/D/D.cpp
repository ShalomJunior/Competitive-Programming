#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    for (auto& c : a) {
        cin >> c;
        mp[c]++;
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int m = a.size();
    int cnt = 0;
    int ans = 0;
    for (int i = 0, j = 1; cnt < 2 * k && i < m - 1; i++) {
        while (cnt < 2 * k && mp[a[i]] && mp[a[j]]) {
            mp[a[i]]--;
            mp[a[j]]--;
            ans += a[i] / a[j];
            cnt += 2;
        }
        if (mp[a[i]] == 0) i = j;
        if (mp[a[j]] == 0 || i == j) j++;
    }
    while (cnt < 2 * k) {
        ans += 1;
        cnt += 2;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}