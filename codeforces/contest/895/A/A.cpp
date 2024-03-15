#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, q; string s;
    cin >> n >> a >> q >> s;
    int in = 0, out = 0;
    int b = a, peak = a;
    for (auto& c : s) {
        if (c == '+') b++, in++;
        else b--, out++;
        peak = max(peak, b);
    }
    if (peak == n) cout << "YES";
    else if (a + in >= n) cout << "MAYBE";
    else cout << "NO";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}