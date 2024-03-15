#include <bits/stdc++.h>
using namespace std;

void f(int a, int b, int c) {
    cout << ((a > max(b, c) ? a - max(b, c) : 0)) << endl;
}
void solve() {
    int a, b, c; cin >> a >> b >> c;
    f(a, b, c);
    f(b, a, c);
    f(c, a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}