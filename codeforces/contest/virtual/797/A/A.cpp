#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, n; cin >> n;
    a = b = c = n / 3;
    if (n % 3 == 0) { a++; c--; }
    else if (n % 3 == 1) { a += 2, c--; }
    else { a += 2, b++, c--; }
    cout << b << " " << a << " " << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}