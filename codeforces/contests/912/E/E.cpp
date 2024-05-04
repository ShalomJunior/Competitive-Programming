#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto it = min_element(a.begin(), a.end());
    if (!is_sorted(it, a.end())) {
        cout << -1 << endl;
        return;
    }
    cout << it - a.begin() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
