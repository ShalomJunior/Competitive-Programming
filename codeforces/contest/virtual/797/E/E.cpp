#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int cost = 0;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ms.insert(x % k);
        cost += x / k;
    }
    while (ms.size() > 1) {
        int b = *ms.begin();
        ms.erase(ms.begin());
        auto it = ms.lower_bound(k - b);
        if (it != ms.end()) {
            cost++;
            ms.erase(it);
        }
    }
    cout << cost << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}