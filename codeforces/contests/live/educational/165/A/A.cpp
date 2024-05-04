#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto& c : p) cin >> c, c--;
    for (int i = 0; i < n; i++) {
        if (p[p[i]] == i) {
            cout << 2 << endl;
            return;
        }
    }
    cout << 3 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
