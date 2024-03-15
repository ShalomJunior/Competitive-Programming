#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

void solve() {
    cout << "TESTCASE" << endl;
    long long l, r;
    cin >> l >> r;
    long long sz = log2((double)r / l) + 1;


    long long ans = 0;
    for (int i = 2; ; i++) {
        cout << "sz = " << sz << endl;
        int up = floor(r / pow(i, sz - 1));
        int down = ((long long)floor(r / pow(i, sz)) < l) ? l - 1 : floor(r / pow(i, sz));
        cout << "up = " << up << "down = " << down << endl;
        int nb = up - down;
        if (nb <= 0) break;
        cout << "nb = " << nb << endl;
        long long sm = pow(i, sz) - (sz + 1);
        cout << "sm = " << nb << endl;
        ans += nb;
        ans %= MOD;
        if (nb == 0)break;
    }

    cout << sz << " " << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}