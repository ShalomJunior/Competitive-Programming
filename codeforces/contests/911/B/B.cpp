#include <bits/stdc++.h>
using namespace std;

void go(int x, int a, int b) {
    cout << ((a + b) & 1 ? 0 : 1) << " ";
}

void solve() {
    int a, b, c; cin >> a >> b >> c;
    go(a, b, c); go(b, a, c); go(c, a, b);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
