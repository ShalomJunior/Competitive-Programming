#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int m = a.size();
    vector<int> b(m);
    b[0] = a[0];
    for (int i = 1; i < m; i++) b[i] = a[i] - a[i - 1];
    vector<bool> alice(m), bob(m);
    alice[m - 1] = bob[m - 1] = true;
    for (int i = m - 2; i >= 0; i--) {
        if (bob[i + 1] == false)
            alice[i] = true;
        if (alice[i + 1] == false)
            bob[i] = true;
        if (b[i] > 1) {
            if (alice[i + 1]) alice[i] = true;
            if (bob[i + 1]) bob[i] = true;
        }
    }
    cout << (alice[0] ? "Alice" : "Bob") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
