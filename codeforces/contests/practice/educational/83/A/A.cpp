#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int x = s[0] - '0', y = s[2] - '0';
    cout << x + y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
