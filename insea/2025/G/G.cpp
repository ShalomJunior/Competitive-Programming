#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0 || b == 0) {
        cout << (c == 0 ? "Yes" : "No");
    }
    else {
        if (a > c / b) {
            cout << "Yes";
        }
        else {
            cout << (a * b >= c ? "Yes" : "No");
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
