#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 30;
void solve() {
    int a, b;
    cin >> a >> b;
    int m = 1;
    while (m <= a) m *= 2;
    if (m - 1 < b) {
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    stringstream ss;
    for (int k = m / 4; k >= 1; k /= 2) {
        int x = a & k;
        int y = b & k;
        if ((!x) && y) {
            cnt++;
            ss << k << " ";
        }
        else if (x && (!y)) {
            cnt++;
            ss << k << " ";
        }
    }
    if (!(b & (m / 2))) {
        cnt++;
        ss << m / 2 << " ";
    }
    ss << endl;
    cout << cnt << endl;
    cout << ss.str() << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
