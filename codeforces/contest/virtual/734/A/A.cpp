#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int q = n / 3, r = n % 3;
    if (r == 0) cout << q << " " << q;
    else if (r == 1) cout << 1 + q << " " << q;
    else cout << q << " " << 1 + q;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}