#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 62;
void solve() {
    int a, b, r;
    cin >> a >> b >> r;
    if (a < b) swap(a, b);
    int v = 0;
    for (int j = N; j >= 0; j--) {
        int mask = 1LL << j;
        int x = a & mask;
        int y = b & mask;
        if (x == y) continue;
        if (x) {
            for (int k = j - 1; k >= 0; k--) {
                mask = 1LL << k;
                x = a & mask;
                y = b & mask;
                if (x == y) continue;
                if (x) {
                    if ((v | mask) <= r) {
                        a -= mask;
                        b += mask;
                        v |= mask;
                    }
                }
            }
            break;
        }
    }
    cout << abs(a - b) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
