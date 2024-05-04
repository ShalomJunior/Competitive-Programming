#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, x, p;
    cin >> n >> x >> p;

    for (ll i = 1; i <= min(p, 2 * n); i++) {
        if ((x + i * (i + 1) / 2) % n == 0) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}