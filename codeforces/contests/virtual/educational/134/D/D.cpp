#include <bits/stdc++.h>
using namespace std;

const int N = 30;
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    int ans = 0;
    int j = N;
    while (j > 0) {
        int mask = 1 << j;
        vector<int> x, y;
        for (int i = 0; i < n; i++) {
            if (a[i] & mask) x.push_back(i);
            if ((a[i] & mask) == 0) y.push_back(i);
        }
        int p = x.size();
        int q = y.size();
        if (p != q) continue;
        for (int i = 0; i < p; i++) swap(b[x[i]], b[y[i]]);
        ans |= mask;
        break;
    }
    while (j >= 0) {
        int mask = 1 << j;
        vector<int> x, y;
        for (int i = 0; i < n; i++) {
            if (a[i] & mask) x.push_back(i);
            if ((a[i] & mask) == 0) y.push_back(i);
        }
        int p = x.size();
        int q = y.size();
        if (p != q) continue;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
