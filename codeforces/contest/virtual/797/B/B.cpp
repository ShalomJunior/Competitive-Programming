#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a)cin >> c;
    for (auto& c : b)cin >> c;
    int M = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] > a[i]) { cout << "NO" << endl;return; }
        M = max(M, a[i] - b[i]);
    }
    bool g = true;
    for (int i = 0; i < n; i++) {
        a[i] -= M;
        if (a[i] < 0) a[i] = 0;
        g &= (a[i] == b[i]);
    }
    cout << ((g) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}