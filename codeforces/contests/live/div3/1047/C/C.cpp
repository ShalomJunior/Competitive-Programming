#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int x = a % 2;
    int y = b % 2;
    if (x == 0) {
        if (y == 0) {
            cout << a * b / 2 + 2;
        }
        else {
            cout << -1;
        }
    }
    else {
        if (y == 0) {
            if (b % 4 == 0) {
                cout << a * b / 2 + 2;
            }
            else {
                cout << -1;
            }
        }
        else {
            cout << a * b + 1;
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
