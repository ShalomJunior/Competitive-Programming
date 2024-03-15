#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    int m = n / 2 + n % 1;
    for (int i = m; i < n; i++) {
        if (s[i] == '0') {
            cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
            return;
        }
    }
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == '0') {
            cout << i + 1 << " " << n << " " << i + 2 << " " << n << endl;
            return;
        }
    }
    cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}