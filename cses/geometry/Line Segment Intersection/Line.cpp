#include <bits/stdc++.h>
#define db double
using namespace std;

const db e = 1e-9;

bool eq(db a, db b) {
    return abs(a - b) < e;
}

void solve() {
    db x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    db a1 = (y1 - y2) / (x1 - x2);
    db b1 = y1 - a1 * x1;
    db a2 = (y3 - y4) / (x3 - x4);
    db b2 = y3 - a2 * x3;

    if (eq(a1, a2)) {
        cout << (eq(b1, b2) ? "YES" : "NO") << endl;
        return;
    }
    db x = (b2 - b1) / (a1 - a2);
    if (min(x1, x2) <= x && x <= max(x1, x2) && min(x3, x4) <= x && x <= max(x3, x4)) {
        cout << "YES" << endl;
    }
    else cout << "NO-" << endl;
    cout << a1 << " " << a2 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}