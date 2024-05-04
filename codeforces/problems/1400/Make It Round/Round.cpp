#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, m; cin >> n >> m;

    for (int i = 18; i > 0; i--) {
        ll a = n, b = pow(10, i);
        ll gd = gcd(a, b);
        a /= gd; b /= gd;
        ll q = m / b;
        if (q) {
            cout << n * b * q << endl;
            return;
        }
    }
    cout << n * m << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}