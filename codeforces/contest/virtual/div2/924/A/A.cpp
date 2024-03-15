#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a % 2 == 0) {
        int x = a / 2, y = 2 * b;
        if (max(a, b) != max(x, y) || min(a, b) != min(x, y)) {
            cout << "YES" << endl;
            return;
        }
    }
    if (b % 2 == 0) {
        int x = 2 * a, y = b / 2;
        if (max(a, b) != max(x, y) || min(a, b) != min(x, y)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}