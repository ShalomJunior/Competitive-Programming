#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> s(n), e(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
    }
    for (int i = 1; i < n; i++) {
        if (s[i] >= s[0] && e[0] <= e[i]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << s[0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
