#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& c : v)cin >> c;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        auto it = upper_bound(v.begin(), v.end(), i);
        if (v.end() - it == i) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}