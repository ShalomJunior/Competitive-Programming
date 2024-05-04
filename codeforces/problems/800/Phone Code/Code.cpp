#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> v(n);
    for (auto& s : v) cin >> s;

    int l = (int)v[0].size();
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j][i] != v[j + 1][i]) {
                cout << i << endl;
                return;
            }
        }
    }
    cout << l << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}