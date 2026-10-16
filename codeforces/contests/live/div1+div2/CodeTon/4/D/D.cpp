#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 3e18;
int f(int a, int b, int h) {
    int m = a - b;
    int q = max(h - a, 0LL) / m;
    while ((q - 1) * m + a < h) q++;
    return max(q, 1LL);
}

void solve() {
    int q;
    cin >> q;
    int L = 0, R = INF;
    while (q--) {
        int t, a, b, n;
        cin >> t >> a >> b;
        if (t == 1) {
            cin >> n;
            int l = n == 1 ? 1 : (n - 1) * (a - b) + b + 1;
            int r = (n - 1) * (a - b) + a;
            int nl = max(L, l);
            int nr = min(R, r);
            if (nl <= nr) {
                cout << 1 << " ";
                L = nl;
                R = nr;
            }
            else {
                cout << 0 << " ";
            }
        }
        else {
            int x = f(a, b, L);
            int y = f(a, b, R);
            cout << (x == y ? x : -1) << " ";
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}