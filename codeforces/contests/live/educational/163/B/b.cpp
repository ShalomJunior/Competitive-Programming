#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int last = -1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x / 10 >= last && x % 10 >= x / 10)
            last = x % 10;
        else if (x >= last)
            last = x;
        else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
