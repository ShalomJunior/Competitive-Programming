#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string x, a, b;
    cin >> n >> x;
    a += '1', b += '1';
    bool f = true;
    for (int i = 1; i < n; i++) {
        if (x[i] == '0') a += '0', b += '0';
        else if (x[i] == '1') {
            if (f) {
                a += '1'; b += '0';
                f = false;
            }
            else { a += '0'; b += '1'; }
        }
        else {
            if (f) { a += '1'; b += '1'; }
            else { a += '0'; b += '2'; }
        }
    }
    cout << a << endl;
    cout << b << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}