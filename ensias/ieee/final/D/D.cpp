#include <bits/stdc++.h>

using namespace std;


const int MOD = 998244353;
const int r = 1000000000 % MOD;

long long solve2 () {
    int n;
    cin >> n;
    string x, y;
    cin >> x; cin >> y;
    if (x < y) {
        string aux = x;
        x = y;
        y = aux;
    }
    long long e = 1;
    long long a = 0, b = 0;
    for (int i = 1; i <= n; ++ i) {
        if (int d1 = x [n - i], d2 = y [n - i]; d1 < d2) {
            a = (a + e * (d2 - '0')) % MOD;
            b = (b + e * (d1 - '0')) % MOD;
        } else {
            a = (a + e * (d1 - '0')) % MOD;
            b = (b + e * (d2 - '0')) % MOD;
        }
        e = (e * 10) % MOD;
    }
    return a * b % MOD;
}
int main () { cout << solve2 ();}
