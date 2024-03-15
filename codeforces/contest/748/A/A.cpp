#include <bits/stdc++.h>
using namespace std;

void f(int a, int b, int c) {
    cout << ((a <= max(b, c) ? max(b, c) - a + 1 : 0)) << " ";
}

void solve() {
    int a, b, c; cin >> a >> b >> c;
    f(a, b, c); f(b, a, c); f(c, a, b);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}