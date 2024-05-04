#include <bits/stdc++.h>
using namespace std;

void solve() {
    char l, d; cin >> l >> d;
    for (int i = 1; i <= 8; i++) {
        if ('0' + i != d) {
            cout << l << i << endl;
        }
        if ('a' + i - 1 != l) {
            cout << (char)('a' + i - 1) << d << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
