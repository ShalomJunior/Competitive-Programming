#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - 1 - i]) {
            cout << (n - 2 * i) << endl;
            return;
        }
    }
    cout << n % 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}