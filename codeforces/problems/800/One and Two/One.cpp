#include <bits/stdc++.h>
#define db double
using namespace std;

const db e = 1e-9;

bool eq(db a, db b) {
    return abs(a - b) < e;
}

void solve() {
    int n; cin >> n;
    vector<db>v(n);
    db r = 1;
    for (auto& c : v) {
        cin >> c;
        r *= c;
    }

    db l = 1;
    for (int i = 0; i < n; i++) {
        l *= v[i]; r /= v[i];
        if (eq(l, r)) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}