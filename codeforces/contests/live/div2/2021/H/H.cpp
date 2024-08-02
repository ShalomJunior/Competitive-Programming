#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    if (l == r) {
        if (l == 0) {
            cout << "Not a moose" << endl;
        }
        else {
            cout << "Even " << l * 2 << endl;
        }
    }
    else {
        int mx = max(l, r);
        cout << "Odd " << mx * 2 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
