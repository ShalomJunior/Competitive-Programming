#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    int d = 0, last = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'R') continue;
        if (last == -1) {
            d = i + 1;
        }
        d = max(d, i - last);
        last = i;
    }
    d = max(d, n - last);
    cout << d << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}