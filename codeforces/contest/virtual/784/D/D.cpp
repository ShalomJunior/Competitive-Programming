#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s; cin >> n >> s;
    int b = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B')b++;
        else if (s[i] == 'R')r++;
        if (s[i] == 'W' || i == n - 1) {
            if (b && !r || r && !b) { cout << "NO" << endl; return; }
            b = r = 0;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}