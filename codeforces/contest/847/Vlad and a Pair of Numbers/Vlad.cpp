#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    if (n & 1) {
        cout << -1 << endl;
        return;
    }

    bitset<32> num(n);
    bitset<32> r(0);
    bitset<32> a, b;

    for (int i = 1; i < 32; i++) {
        if (num[i] ^ num[i - 1]) {
            r.set(i - 1);
        }

        if (r[i - 1] ^ r[i - 2] & (num[i - 1])) {
            a.set(i - 1);
            b.set(i - 1);
        }
        else if (num[i - 1]) {
            if (b.count() == 0)
                b.set(i - 1);
            else a.set(i - 1);
        }
    }

    int mx = a.to_ulong();
    int mn = b.to_ulong();

    if (mx + mn != 2 * n || (mx ^ mn) != n)
        cout << -1 << endl;
    else
        cout << mx << " " << mn << endl;
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}