#include <bits/stdc++.h>
#define int long long
using namespace std;

int A, B, C, k;
void solve() {
    cin >> A >> B >> C >> k;
    int amin = pow(10, A - 1), amax = pow(10, A);
    int bmin = pow(10, B - 1), bmax = pow(10, B);
    int cmin = pow(10, C - 1), cmax = pow(10, C);
    if (cmax <= amin + bmin || amax + bmax <= cmin) {
        cout << -1 << endl;
        return;
    }
    for (int i = bmax - 1; i >= bmin; i--) {
        int a = cmax - 1 - i;
        if () {

        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}