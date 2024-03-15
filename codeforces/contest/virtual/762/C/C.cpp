#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, s; cin >> a >> s;
    string b;
    while (s > 0) {
        int x = s % 10;
        int y = a % 10;
        if (x >= y) {
            char c = '0' + x - y;
            b = c + b;
            a /= 10, s /= 10;
        }
        else {
            if (s >= 10) {
                s /= 10;
                int z = s % 10;
                int n = 10 * z + x;
                if (n - y < 0 || n - y >= 10) {
                    cout << -1 << endl;
                    return;
                }
                else {
                    char c = '0' + n - y;
                    b = c + b;
                    a /= 10, s /= 10;
                }
            }
            else {
                cout << -1 << endl;
                return;
            }
        }
    }
    while (b.length() > 1 && b[0] == '0') {
        b = b.substr(1, b.length() - 1);
    }
    if (b.length() == 0) b = "0";
    cout << (a ? "-1" : b) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
