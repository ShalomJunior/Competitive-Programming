#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int k, x, a;
    cin >> k >> x >> a;
    if (a == 1 && x > 0) {
        cout << "NO" << endl;
        return;
    }
    vector<int> bet(x + 2), lost(x + 2);
    bet[1] = lost[1] = 1;
    for (int i = 2; i <= x + 1; i++) {
        int b = lost[i - 1] / (k - 1);
        if (b * (k - 1) <= lost[i - 1])b++;
        if (b > a - lost[i - 1]) {
            cout << "NO" << endl;
            return;
        }
        bet[i] = b;
        lost[i] = lost[i - 1] + b;
    }
    cout << "YES" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
