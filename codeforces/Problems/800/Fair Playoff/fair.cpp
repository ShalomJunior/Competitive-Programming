#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int>v(4);
    for (int i = 0; i < 4; i++) cin >> v[i];
    int sm = max(v[0], v[1]) + max(v[2], v[3]);
    sort(v.begin(), v.end());
    sm -= v[2] + v[3];
    if (sm) cout << "NO\n";
    else cout << "YES\n";
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}