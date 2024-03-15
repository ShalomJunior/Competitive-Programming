#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;

    for (ll x = a + 1; x <= c; x++) {
        ll gd = gcd(a * b, x);
        ll y = (a * b) / gd;

        if (y > d) continue;
        y *= (d / y);
        if (y > b) {
            cout << x << " " << y << endl;
            return;
        }
    }
    cout << "-1 -1" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}