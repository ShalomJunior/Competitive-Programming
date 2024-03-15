#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (n == 1) {
        for (int i = 0; i < 3; i++) {
            cout << 1 << " " << 1 << endl;
            cout << -a[0] << endl;
            a[0] = 0;
        }
        return;
    }
    cout << 1 << " " << n - 1 << endl;
    for (int i = 0; i < n - 1; i++) {
        int r = a[i] % n;
        if (r < 0) r = n + r;
        int add = r * (n - 1);
        a[i] += add;
        cout << add << " ";
    }
    cout << endl;
    cout << n << " " << n << endl;
    cout << -a[n - 1] << endl;
    a[n - 1] = 0;
    cout << 1 << " " << n << endl;
    for (int i = 0; i < n; i++) {
        cout << -a[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
