#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    int cnt = r - l;
    if (cnt) {
        cout << cnt;
    }
    else {
        cout << (l == 1 ? 1 : 0);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}