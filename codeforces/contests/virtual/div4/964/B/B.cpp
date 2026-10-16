#include <bits/stdc++.h>
using namespace std;

int f(int a, int b, int x, int y) {
    if (a > x && b >= y) return 1;
    if (a == x && b > y) return 1;
    return 0;
}

void solve() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << (f(a, b, x, y) + f(b, a, x, y)) * 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}