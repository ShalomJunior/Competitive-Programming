#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; char c; string s;
    cin >> n >> c >> s;
    if (count(s.begin(), s.end(), c) == n) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == c) {
            bool b = true;
            for (int j = i; j < n; j += i + 1) {
                b &= s[j] == c;
            }
            if (b) {
                cout << 1 << endl << i + 1 << endl;
                return;
            }
        }
    }
    cout << 2 << endl;
    cout << n << " " << n - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}