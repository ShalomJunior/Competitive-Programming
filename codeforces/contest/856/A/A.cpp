#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;

    vector<vector<string>> v(n);
    for (int i = 0; i < 2 * n - 2; i++) {
        string s; cin >> s;
        v[s.length()].push_back(s);
    }

    for (int i = 1; i < n; i++) {
        reverse(v[i][1].begin(), v[i][1].end());
        if (v[i][0] != v[i][1]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}




int main() {
    int t; cin >> t;
    while (t--) solve();
}