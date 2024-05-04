#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    if (a < b) cout << (a % 2 == b % 2 ? 2 : 1);
    else if (a == b) cout << 0;
    else cout << (a % 2 == b % 2 ? 1 : 2);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}