#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q; cin >> q;
    map<int, int> L, R;
    int l = 0, r = 0;
    while (q--) {
        char c; int id;
        cin >> c >> id;
        if (c == 'L') L[id] = ++l;
        else if (c == 'R') R[id] = ++r;
        else {
            if (L.count(id)) {
                cout << min(l - L[id], L[id] - 1 + r) << endl;
            }
            else {
                cout << min(r - R[id], R[id] - 1 + l) << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}