#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    vector<int> x(n), y(n);
    multiset<int> ms(b.begin(), b.end());
    for (int i = n - 1; i >= 0; i--) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        x[i] = *it - a[i];
        y[i] = *prev(ms.end()) - a[i];
        ms.erase(ms.lower_bound(a[i]));
    }
    for (auto& c : x) cout << c << " ";
    cout << endl;
    for (auto& c : y) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
