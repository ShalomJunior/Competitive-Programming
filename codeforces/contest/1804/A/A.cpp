#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    a = abs(a);
    b = abs(b);
    int ans = 2 * min(a, b);
    if (a < b)
        ans += 2 * (b - a) - 1;
    else if (a > b)
        ans += 2 * (a - b) - 1;

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}