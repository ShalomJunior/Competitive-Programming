#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    bool good = true;
    for (int i = 0; i < n; i++) {
        good &= a[i] <= b[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            good &= (b[(i + 1) % n] >= b[i] - 1);
        }
    }
    cout << (good ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}