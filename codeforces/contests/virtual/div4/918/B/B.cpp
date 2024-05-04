#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    vector<int> x(3);
    for (auto& s : { a, b, c }) {
        for (auto& l : s) {
            if (l != '?') x[l - 'A']++;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (x[i] != 3) {
            cout << (char)('A' + i) << endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}