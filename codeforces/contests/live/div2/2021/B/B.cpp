#include <bits/stdc++.h>
#define int long long
using namespace std;

int exp(int a, int b, int MOD) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

bool is(int n) {
    if (n < 4) return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, p;
    do {
        cin >> p >> a;
        if (a == 0 && p == 0) break;
        cout << (!is(p) && exp(a, p, p) == a ? "yes" : "no") << endl;
    } while (true);
}
