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
    string s; cin >> s;
    s = "#" + s;
    deque<int> L, R;
    for (int i = 1; i <= n; i++) {
        s[i] == 'L' ? L.push_back(i) : R.push_back(i);
    }
    int can = 0;
    int start = 0;
    int end = count(s.begin() + 1, s.end(), 'R');
    for (int i = 1; i <= n; i++) {
        s[i] == 'L' ? start++ : end--;
        if (start >= end) can = max(can, min(start, end));
    }
    auto query = [&](int l, int r) {
        return pref[r] - pref[l - 1];
        };
    int ans = 0;
    while (L.size() > can) L.pop_back();
    while (R.size() > can) R.pop_front();
    while (!L.empty() && !R.empty()) {
        int l = L.front();
        int r = R.front();
        L.pop_front();
        R.pop_front();
        ans += query(l, r);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
