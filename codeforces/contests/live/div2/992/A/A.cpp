#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    for (int i = 0; i < n; i++) {
        bool b = true;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (abs(a[i] - a[j]) % k == 0) b = false;
        }
        if (b) {
            cout << "YES" << endl;
            cout << i + 1 << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
