#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);
    set<int> all;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        all.insert(pref[i]);
    }
    int cnt = 0;
    stringstream ss;
    for (auto& x : all) {
        int v = x;
        while (all.count(v) && v != pref[n]) v += x;
        if (v == pref[n]) {
            if (x > 1 && pref[n] / x > 1) {
                cnt++;
                ss << x << " " << pref[n] / x << '\n';
            }
        }
    }
    cout << cnt << endl;
    cout << ss.str();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}