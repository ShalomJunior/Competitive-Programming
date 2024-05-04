#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    if (n == 2) {
        cout << a.back() + 1 << endl;
        return;
    }
    int k = 2;
    while (true) {
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(a[i] % k);
        }
        if (s.size() == 2) {
            cout << k << endl;
            return;
        }
        k *= 2;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
