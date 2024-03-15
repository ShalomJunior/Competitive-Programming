#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;

    if (a[n - 1] < b[n - 1]) swap(a[n - 1], b[n - 1]);
    for (int i = 0; i < n - 1; i++) {
        int mn = min(a[i], b[i]);
        int mx = max(a[i], b[i]);
        bool ck = (mn <= b[n - 1] && mx <= a[n - 1]);
        if (!ck) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}