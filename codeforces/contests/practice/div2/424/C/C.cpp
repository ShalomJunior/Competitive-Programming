#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k, n;
    cin >> k >> n;
    vector<int> a(k + 1);
    vector<int> pref(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    vector<int> b(n);
    for (auto& c : b) cin >> c;
    set<int> ans;
    for (int i = 1; i <= k; i++) {
        set<int> all(b.begin(), b.end());
        int x = b[0] - pref[i];
        for (int j = 1; j <= k; j++) all.erase(x + pref[j]);
        if (all.empty()) ans.insert(x);
    }
    cout << ans.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
