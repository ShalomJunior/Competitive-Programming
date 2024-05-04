#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int x = 1;
    int y = 1 + n / 2;
    while (x <= n / 2 && y <= n) {
        cout << y << " " << x << " ";
        x++, y++;
    }
    if (n & 1)cout << n;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}