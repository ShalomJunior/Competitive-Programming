#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        c & 1 ? x++ : y++;
    }
    int a = y / 2, b = y / 2;
    if (y & 1) {
        a++;
        if (x >= 2) b++;
    }
    cout << (a != b || x & 1 ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}