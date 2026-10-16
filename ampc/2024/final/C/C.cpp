#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;
int exp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int inv(int a) {
    return exp(a, MOD - 2);
}

void brute(int q, int p, int r, int n) {
    n = (n * 12 + 1);
    vector<vector<int>> a(n, vector<int>(3));
    a[0][0] = q;
    a[0][1] = p;
    a[0][2] = r;
    for (int i = 1; i < n; i++) {
        a[i][0] = (a[i - 1][0] * 2 + a[i - 1][1] + a[i - 1][2] + 2) % MOD;
        a[i][1] = (a[i - 1][0] + a[i - 1][1]) % MOD;
        a[i][2] = (a[i - 1][0] + a[i - 1][2] + 1) % MOD;
    }
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < n; i++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    int q, p, r, n;
    cin >> q >> p >> r >> n;
    int qr = q;
    for (int i = 1; i < 25; i++) {
        cout << "i = " << i << endl;
        qr = qr * 3 + 1;
        qr %= MOD;
        cout << qr << " -> " << endl;
        int m = exp(3, i);
        int ans = m * q % MOD + m * inv(2) % MOD - inv(2);

        //ans += MOD - inv(2);
        ans = (ans + MOD) % MOD;
        // (q + 0.5) % MOD - 0.5;
        // int val = m * (q + inv(2));
        // val %= MOD;
        // val = MOD - inv(2);
        // val %= MOD;
        //cout << "-> "val << endl;
        cout << ans << endl;
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //brute(0, 2, 0, 2);
    brute(0, 2, 4, 2);

    //cout << inv(2) << endl;
    // int q, n;
    // cin >> q >> n;
    // //for (int i = 0; i < 100; i++) {
    // double val = exp(3, n * 12) * q;
    // int sec = exp(3, n * 12) * 0.5 - 0.5;
    // cout << val << " " << sec << " " << val + sec << endl;
    //cout << exp(3, 2 * 12) * 1 + exp(3, 2 * 12) * 0.5 - 0.5 << endl;
//}
    // int q = 0;
    // for (int i = 0; i < 25; i++) {
    //     q = q * 3 + 1;
    //     q %= MOD;
    //     cout << q << " ";
    // }
    // cout << endl;
    int t = 1;
    // cin >> t;
    while (t--)solve();
}