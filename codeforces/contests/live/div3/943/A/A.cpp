#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;
    int Y = 1;
    int s = 0;
    for (int y = 1; y < x; y++) {
        if (__gcd(x, y) + y >= s) {
            Y = y;
            s = __gcd(x, y) + y;
            cerr << s << endl;
        }
    }
    cout << Y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
