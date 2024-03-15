#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    multiset<int> ms(a.begin(), a.end());
    int ans = 0;
    for (int i = n; i > 0; i--) {
        auto it = ms.lower_bound(i);
        if (it != ms.end() && *it == i) {
            ms.erase(it);
            continue;
        }
        it = ms.lower_bound(2 * i + 1);
        if (it == ms.end()) {
            cout << -1 << endl;
            return;
        }
        ms.erase(it);
        ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}