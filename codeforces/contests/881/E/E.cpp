#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> seg(m);
    for (auto& [f, s] : seg) {
        cin >> f >> s;
        --f, --s;
    }
    int q; cin >> q;
    vector<int> flip(q);
    for (auto& c : flip) {
        cin >> c; c--;
    }
    int L = 0, R = q - 1;
    while (L <= R) {
        int mid = (L + R) / 2;
        vector<int> a(n);
        for (int i = 0; i <= mid; i++) {
            a[flip[i]] = 1;
        }
        vector<int> pref(n);
        for (int i = 0; i < n; i++) {
            pref[i] = a[i] + (i ? pref[i - 1] : 0);
        }
        bool good = false;
        for (auto& [l, r] : seg) {
            int need = 1 + ((r - l + 1) / 2);
            int have = pref[r] - (l ? pref[l - 1] : 0);
            if (have >= need) { good = true; break; }
        }
        if (good) {
            if (L == R) { cout << L + 1 << endl; return; }
            else R = mid;
        }
        else L = mid + 1;
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}