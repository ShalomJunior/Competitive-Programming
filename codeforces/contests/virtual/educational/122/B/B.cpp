#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int x = 0, y = 0;
    for (auto& c : s) {
        c == '0' ? x++ : y++;
    }
    cout << (x != y ? min(x, y) : x - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
