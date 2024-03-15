#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (is_sorted(a.begin(), a.end())) {
        cout << 0 << endl;
        return;
    }
    if (n > 3) {
        int y = a[0], z = a[1];
        if (y < z) swap(y, z);
        cout << n << endl;
        cout << n << " " << y << " " << z << endl;
        cout << n - 1 << " " << y << " " << z << endl;
        for (int i = n - 2; i > 0; i--) {
            cout << i << " " << n - 1 << " " << n << endl;
        }
    }
    else {

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}