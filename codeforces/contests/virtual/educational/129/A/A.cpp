#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto& c : b) cin >> c;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << (a.back() >= b.back() ? "Alice" : "Bob") << endl;
    cout << (b.back() >= a.back() ? "Bob" : "Alice") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
