#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int x = count(s.begin(), s.end(), '0');
    if (x == n) {
        cout << 0 << endl;
    }
    else {
        cout << x << endl;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
