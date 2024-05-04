#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        a[c - 1].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        auto v = a[i];
        int o = 0, e = 0;
        for (auto& j : v) {
            j & 1 ? o++ : e++;
        }
        cout << max(o, e) << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}