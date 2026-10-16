#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 31;
void solve() {
    int l, r;
    cin >> l >> r;
    int add = 0;
    for (int j = N; j >= 0; j--) {
        int mask = 1 << j;
        if ((l & mask) ^ (r & mask)) {
            int x = mask;
            int y = x - 1;
            x += add;
            y += add;
            int z = l;
            while (z == x || z == y) z++;
            cout << x << " " << y << " " << z << endl;
            return;
        }
        else if (l & mask) add |= mask;
    }
    assert(false);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}