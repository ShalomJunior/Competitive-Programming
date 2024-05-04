#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y; cin >> x >> y;
    if (y % x) { cout << "0 0\n"; return; }
    for (int a = 1; a <= 100; a++) {
        for (int b = 1; b <= 100; b++) {
            if (pow(b, a) == y / x) {
                cout << a << " " << b << endl;
                return;
            }
        }
    }
    cout << "0 0\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}