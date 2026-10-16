#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] != -1) {
            s.insert(a[i] + b[i]);
        }
    }
    if (s.size() > 1) {
        cout << 0 << endl;
        return;
    }
    if (!s.empty()) {
        int x = *s.begin();
        for (int i = 0; i < n; i++) {
            int v = x - a[i];
            if (b[i] == -1 && (v < 0 || v > k)) {
                cout << 0 << endl;
                return;
            }
        }
        cout << 1 << endl;
    }
    else {
        sort(a.begin(), a.end());
        cout << k + a[0] - a[n - 1] + 1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
