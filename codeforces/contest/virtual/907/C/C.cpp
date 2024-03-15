#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    vector<long long> pref(n);
    for (int i = 0; i < n; i++) {
        pref[i] = a[i] + (i ? pref[i - 1] : 0);
    }
    long long mid = (pref[n - 1] + 1) / 2;
    auto it = lower_bound(pref.begin(), pref.end(), mid);
    if (*it == mid) it++;
    long long ans = mid + pref.end() - it;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}