#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1 && k == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    if (k & 1) {
        if (k == 1 || k == n) {
            cout << -1 << endl;
        }
        else {
            cout << 5 << endl;
            cout << 1 << " " << k - 1 << " " << k << " " << k + 1 << " " << k + 2 << endl;
        }
    }
    else {
        cout << 3 << endl;
        cout << 1 << " " << k << " " << k + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
