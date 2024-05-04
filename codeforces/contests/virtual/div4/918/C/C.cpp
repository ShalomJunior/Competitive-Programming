#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    long long tot = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        tot += x;
    }
    long long c = sqrtl(tot);
    if (c * c == tot || (c + 1) * (c + 1) == tot) {
        cout << "YES";
    }
    else cout << "NO";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}