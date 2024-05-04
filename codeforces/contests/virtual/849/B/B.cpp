#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    int x = 0, y = 0;
    for (auto& c : s) {
        if (c == 'L') x--;
        else if (c == 'R') x++;
        else if (c == 'D') y--;
        else y++;
        if (x == 1 && y == 1) { cout << "YES" << endl; return; }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}