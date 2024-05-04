#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string a, b;
    cin >> n >> a >> b;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) x++;
        if (a[i] != b[n - 1 - i]) y++;
    }
    cout << min(2 * x - x % 2, y == 0 ? 2 : 2 * y - (1 - y % 2)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}