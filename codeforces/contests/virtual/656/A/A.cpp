#include <bits/stdc++.h>
using namespace std;

void f(int a, int b, int c) { cout << "YES\n" << a << " " << b << " " << c << endl; }

void solve() {
    int x, y, z; cin >> x >> y >> z;
    int M = max({ x,y,z });
    if (x == y && x == M) f(x, z, z);
    else if (x == z && x == M) f(y, x, y);
    else if (y == z && y == M) f(x, x, z);
    else cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}