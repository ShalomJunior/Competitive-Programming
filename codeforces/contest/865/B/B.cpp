#include <bits/stdc++.h>

using namespace std;

void out(vector<int>& v) {
    for (auto& c : v)cout << c << " ";
    cout << endl;
}

void solve() {
    int n; cin >> n;
    vector<int> f(n), s(n);
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            f[i] = i;
            s[i] = 2 * n - i;
        }
        else {
            f[i] = 2 * n - i;
            s[i] = i + 2;
        }
    }
    out(f); out(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}