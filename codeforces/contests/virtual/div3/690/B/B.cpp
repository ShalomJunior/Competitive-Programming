#include <bits/stdc++.h>
using namespace std;

const string match = "2020";
void solve() {
    int n; string s;
    cin >> n >> s;
    bool b = false;
    int L = 4;
    for (int i = 0; i <= L; i++) {
        string t = s.substr(0, i) + s.substr(n - (L - i), 4 - i);
        b |= t == match;
    }
    cout << (b ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}