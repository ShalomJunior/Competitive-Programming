#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    unordered_set<string> s;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    string ans(n, '0');
    for (int i = 0; i < n; i++) {
        int z = a[i].size();
        for (int j = 1; j < z; j++) {
            if (s.count(a[i].substr(0, j)) && s.count(a[i].substr(j, z - j))) {
                ans[i] = '1'; break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}