#include <bits/stdc++.h>
using namespace std;

bool in(int l1, int r1, int l2, int r2) {
    return l2 < l1 && r1 < r2;
}
void solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int l = max(l1, l2);
    int r = min(r1, r2);
    if (l1 == l2 && r1 == r2) {
        cout << r1 - l1;
    }
    else if (l1 == l2) {
        cout << r - l1 + 1;
    }
    else if (r1 == r2) {
        cout << r1 - l + 1;
    }
    else {
        if (l > r) {
            cout << 1;
        }
        else if (in(l1, r1, l2, r2) || in(l2, r2, l1, r1)) {
            cout << r - l + 2;
        }
        else {
            cout << r - l;
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
