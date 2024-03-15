#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 998244353;

ll dig(char c) { return (ll)(c - '0'); }

int main() {
    int n; cin >> n;
    string x, y; cin >> x; cin >> y;

    for (int i = 0; i < n; i++) {
        if (x[i] < y[i]) swap(x[i], y[i]);
    }

    ll m = 1, a = 0, b = 0;
    for (int i = n - 1; i >= 0; i--) {
        a = (a + m * dig(x[i])) % MOD;
        b = (b + m * dig(y[i])) % MOD;
        m = (m * 10) % MOD;
    }
    cout << (a * b) % MOD << endl;
}