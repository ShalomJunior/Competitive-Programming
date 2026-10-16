#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a & 1) {
        cout << "NO";
    }
    else {
        if (b == 0) {
            cout << "YES";
        }
        else {
            b += a / 2;
            cout << (b & 1 ? "NO" : "YES");
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
