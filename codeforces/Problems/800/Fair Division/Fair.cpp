#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int c1 = 0, c2 = 0;
    int x, sm = 0;
    while (n--) {
        cin >> x;
        (x == 1) ? c1++ : c2++;
    }

    if (c1 % 2 == 0 && c2 % 2 == 0) cout << "YES\n";
    else if (c1 % 2 == 0 && c2 % 2 != 0) {
        if (c1 >= 2) cout << "YES\n";
        else cout << "NO\n";
    }
    else cout << "NO\n";

}

int main() {
    int t; cin >> t;
    while (t--)solve();
}