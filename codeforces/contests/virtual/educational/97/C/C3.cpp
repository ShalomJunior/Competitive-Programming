#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (auto& c : t) cin >> c;
    sort(t.begin(), t.end());
    int ans = 0;
    multiset<int> in;
    for (int i = 1, j = 0; i <= 2 * n; i++) {
        while (j < n && t[j] <= i) in.insert(t[j++]);
        if (!in.empty()) {
            ans += i - *prev(in.end());
            in.erase(prev(in.end()));
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
