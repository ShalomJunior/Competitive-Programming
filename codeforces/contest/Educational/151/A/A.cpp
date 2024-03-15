#include <bits/stdc++.h>
using namespace std;

void f(int n, int x) {
    for (int i = 0; i < n; i++) cout << x << " ";
    cout << endl;
}

void solve() {
    int n, k, x; cin >> n >> k >> x;
    if (x != 1) {
        cout << "YES" << endl;
        cout << n << endl;
        f(n, 1);
    }
    else {
        if (n == 1 || k == 1) cout << "NO" << endl;
        else {
            if (n & 1) {
                if (k < 3) cout << "NO" << endl;
                else {
                    cout << "YES" << endl;
                    int cnt = (n - 3) / 2;
                    cout << 1 + cnt << endl;
                    cout << "3 ";
                    f(cnt, 2);
                }
            }
            else {
                cout << "YES" << endl;
                cout << n / 2 << endl;
                f(n / 2, 2);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}