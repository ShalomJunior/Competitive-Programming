#include <bits/stdc++.h>
#define ll long long
using namespace std;

void out(int n) {
    cout << n << endl;
}
void solve() {
    ll l, r, x; cin >> l >> r >> x;
    ll a, b; cin >> a >> b;

    ll ans = 0;
    if (a == b)cout << 0 << endl;
    else if (a < b) {
        if (a + x <= b) {
            out(1); return;
        }
        if (b + x <= r || a - x >= l) {
            out(2); return;
        }
        if (r - a >= x && b - x >= l) {
            out(3); return;
        }
        else {
            cout << -1 << endl;
            return;
        }
    }
    else {
        if (a - x >= b) {
            out(1); return;
        }

        if (b - x >= l || a + x <= r && r - b >= x) {
            out(2); return;
        }
        else if (a - x >= l && r - l >= x && b + x <= r) {
            out(3); return;
        }
        else {
            cout << -1 << endl;
            return;
        }

    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}