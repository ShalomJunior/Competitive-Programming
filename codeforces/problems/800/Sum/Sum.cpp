#include <bits/stdc++.h>


using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b + c || b == a + c || c == a + b) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}