#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<bool> b(n);
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] + a[i + 1] < a[i])
            b[i] = true;
    }
    if (k == 1) {
        int len = n - 2;
        cout << (len + 1) / 2 << endl;
    }
    else {
        cout << count(b.begin(), b.end(), true) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}