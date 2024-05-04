#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s; cin >> n >> s;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
        case 'L': {x--; break;}
        case 'R': {x++; break;}
        case 'U': {y++; break;}
        case 'D': {y--; break;}
        }
        if (x == 1 && y == 1) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}