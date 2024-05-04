#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    int e = c - a;
    int ans = 1e7, x, y, z;
    for (int i = 1; i <= a + e; i++) {
        for (int j = i; j <= b + e; j += i) {
            int k = (j < c ? min(c % j, j - (c % j)) : j - c);
            int delta = abs(a - i) + abs(b - j) + k;
            if (delta < ans) {
                ans = delta;
                x = i, y = j;
                if (((c + k) % j) == 0) z = c + k;
                else z = c - k;
            }
        }
    }
    cout << ans << endl;
    cout << x << " " << y << " " << z << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}