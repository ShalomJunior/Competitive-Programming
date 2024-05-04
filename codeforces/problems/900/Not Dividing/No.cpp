#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& c : v) {
        cin >> c;
        if (c == 1)c++;
    }

    for (int i = 1; i < n; i++) {
        if (v[i] % v[i - 1] == 0) v[i]++;
    }

    for (auto& c : v) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}