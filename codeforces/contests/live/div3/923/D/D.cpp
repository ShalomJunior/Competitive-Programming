#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, vector<int>> h;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        h[a[i]].push_back(i);
    }
    vector<int> next(n);
    for (int i = 0; i < n; i++) {
        int L = i + 1, R = n;
        auto& vec = h[a[i]];
        auto f = lower_bound(vec.begin(), vec.end(), i);
        while (L < R) {
            int mid = (L + R) / 2;
            auto s = lower_bound(vec.begin(), vec.end(), mid);
            if (s - f + 1 == mid - i + 1 && s != vec.end() && *s == mid) L = mid + 1;
            else R = mid;
        }
        next[i] = L;
    }
    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r; --l, --r;
        auto& vec = h[a[r]];
        auto f = lower_bound(vec.begin(), vec.end(), l);
        auto s = lower_bound(vec.begin(), vec.end(), r);
        if (s - f + 1 == r - l + 1) {
            cout << -1 << " " << -1 << endl;
            continue;
        }
        cout << l + 1 << " " << next[l] + 1 << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
