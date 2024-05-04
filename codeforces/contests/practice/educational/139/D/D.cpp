#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y; cin >> x >> y;
    if (x > y) swap(x, y);
    if (gcd(x, y) != 1) {
        cout << 0 << endl;
        return;
    }
    int d = y - x;
    if (d == 1) {
        cout << -1 << endl;
        return;
    }
    bool f = false;
    vector<int> r;
    for (int i = 1; i * i <= d; i++) {
        if (d % i == 0) {
            int a = i, b = d / i;
            if (a != 1) r.push_back(a - x % a);
            r.push_back(b - x % b);
            f = true;
        }
    }
    cout << (f ? *min_element(r.begin(), r.end()) : 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
