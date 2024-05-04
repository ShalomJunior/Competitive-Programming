#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    multiset<int> m(a.begin(), a.end());
    for (int i = 2 * n - 2; i >= 0; i--) {
        auto ms = m;
        stringstream ss;
        ss << "YES" << endl;
        int x = a[2 * n - 1] + a[i];
        ss << x << endl;
        while (!ms.empty()) {
            int M = *prev(ms.end());
            ms.erase(prev(ms.end()));
            auto it = ms.lower_bound(x - M);
            if (it == ms.end() || M + *it != x) break;
            x = M;
            ss << *it << " " << M << endl;
            ms.erase(it);
        }
        if (ms.empty()) {
            cout << ss.str();
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}