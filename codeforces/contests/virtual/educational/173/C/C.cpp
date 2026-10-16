#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(vector<int> a, bool rev) {
    int n = a.size();
    if (n == 0) return 0;
    if (rev) for (auto& c : a) c *= -1;
    int best = 0;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr = max(curr + a[i], a[i]);
        best = max(best, curr);
    }
    return rev ? -best : best;
}

pair<int, int> g(vector<int> a, bool rev) {
    int n = a.size();
    if (n == 0) return { 0, 0 };
    if (rev) reverse(a.begin(), a.end());
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
        pref[i] = a[i] + (i ? pref[i - 1] : 0LL);
    }
    int mn = *min_element(pref.begin(), pref.end());
    int mx = *max_element(pref.begin(), pref.end());
    return make_pair(min(mn, 0LL), max(mx, 0LL));
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int j = 0;
    while (j < n && abs(a[j]) == 1) j++;
    vector<int> L;
    for (int i = 0; i < j; i++) L.push_back(a[i]);
    vector<int> R;
    for (int i = j + 1; i < n; i++) R.push_back(a[i]);
    int l1 = f(L, true);
    int r1 = f(L, false);
    int l2 = f(R, true);
    int r2 = f(R, false);
    auto l = g(L, true);
    auto r = g(R, false);
    set<int> ans;
    for (int i = l1; i <= r1; i++) ans.insert(i);
    for (int i = l2; i <= r2; i++) ans.insert(i);
    for (int i = l.first + r.first; i <= l.second + r.second && j < n; i++) ans.insert(a[j] + i);
    cout << ans.size() << endl;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
